#include <zephyr.h>

#if defined(CONFIG_STDOUT_CONSOLE)
#include <stdio.h>
#else
#include <sys/printk.h>
#endif

#include <sys/__assert.h>

#define STACK_SIZE (768 + CONFIG_TEST_EXTRA_STACKSIZE)

static K_THREAD_STACK_ARRAY_DEFINE(stacks, 2, STACK_SIZE);
static struct k_thread threads[2];

K_MUTEX_DEFINE( cliblock );	

#include <stdarg.h>

static int32_t get_random_delay(int id, int period_in_ms)
{
	/*
	 * The random delay is unit-less, and is based on the philosopher's ID
	 * and the current uptime to create some pseudo-randomness. It produces
	 * a value between 0 and 31.
	 */
	int32_t delay = (k_uptime_get_32()/100 * (id + 1)) & 0x1f;

	/* add 1 to not generate a delay of 0 */
	int32_t ms = (delay + 1) * period_in_ms;

	return ms;
}

void philosopher(void *id, void *unused1, void *unused2)
{
	ARG_UNUSED(unused1);
	ARG_UNUSED(unused2);
	
	int my_id = POINTER_TO_INT(id);
	
	printk("Beginning execution; thread data is %d\n", my_id);

	k_msleep(200);

	while (1) {
		int32_t delay;
		
		delay = 200 + get_random_delay(my_id, 25);
		
		k_mutex_lock(&cliblock, K_FOREVER);
		
		printk("Thread %d: and now a delay of %d clock ticks\n", my_id, delay);
		
		k_mutex_unlock(&cliblock);
		
		k_msleep(delay);		
	}
}

static void start_threads(void)
{
	//Crear hilo 0	
	k_thread_create(&threads[0], &stacks[0][0], STACK_SIZE,
			philosopher, INT_TO_POINTER(0), NULL, NULL,
			0, K_USER, K_FOREVER);
	
	k_object_access_grant(&cliblock, &threads[0]);
	k_object_access_grant(&cliblock, &threads[1]);
	
	k_thread_start(&threads[0]);
	
	//Crear hilo 1	
	k_thread_create(&threads[1], &stacks[1][0], STACK_SIZE,
		philosopher, INT_TO_POINTER(1), NULL, NULL,
		0, K_USER, K_FOREVER);	
		
	k_thread_start(&threads[1]);
}

void main(void)
{
	//display_demo_description();
#if CONFIG_TIMESLICING
	k_sched_time_slice_set(5000, 0);
#endif	
	
	k_mutex_init(&cliblock);	//Inicializar Mutex	
	start_threads();

#ifdef CONFIG_COVERAGE
	/* Wait a few seconds before main() exit, giving the sample the
	 * opportunity to dump some output before coverage data gets emitted
	 */
	k_sleep(K_MSEC(5000));
#endif
}
