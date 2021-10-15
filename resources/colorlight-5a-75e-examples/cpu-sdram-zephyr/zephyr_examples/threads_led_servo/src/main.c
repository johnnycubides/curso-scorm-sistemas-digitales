#include <zephyr.h>

#if defined(CONFIG_STDOUT_CONSOLE)
#include <stdio.h>
#else
#include <sys/printk.h>
#endif

#include <sys/__assert.h>


#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/pwm.h>

/* #################### START LED #################### */
#define SLEEP_TIME_MS   250
/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: led0 devicetree alias is not defined"
#define LED0	""
#define PIN	0
#define FLAGS	0
#endif

/* #################### END LED #################### */

/* #################### START SERVO #################### */
#define PWM_NODE DT_ALIAS(pwm_servo)

#if !DT_NODE_HAS_STATUS(PWM_NODE, okay)
#error "Unsupported board: pwm-servo devicetree alias is not defined or enabled"
#define PWM_LABEL ""
#else
#define PWM_LABEL DT_LABEL(PWM_NODE)
#endif

/*
 * Unlike pulse width, the PWM period is not a critical parameter for
 * motor control. 20 ms is commonly used.
 */
#define PERIOD_USEC	(20U * USEC_PER_MSEC)
#define STEP_USEC	300
#define MIN_PULSE_USEC	500
#define MAX_PULSE_USEC	1300

/* #################### END SERVO #################### */

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

/* #################### START LED #################### */
void blinkLed(void *id, void *unused1, void *unused2)
{
	ARG_UNUSED(unused1);
	ARG_UNUSED(unused2);
	int my_id = POINTER_TO_INT(id);

	const struct device *dev;
	bool led_is_on = true;
	int ret;

	printk("Beginning execution; thread data is %d\n", my_id);
	k_msleep(200);

	dev = device_get_binding(LED0);
	if (dev == NULL) {
		return;
	}

	ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
	if (ret < 0) {
		return;
	}


	while (1) {
		k_mutex_lock(&cliblock, K_FOREVER);
		/* printk("Thread %d: and now a delay of %d clock ticks\n", my_id, delay); */
		printk("Thread %d \n", my_id);

		gpio_pin_set(dev, PIN, (int)led_is_on);
		led_is_on = !led_is_on;

		k_mutex_unlock(&cliblock);
		k_msleep(SLEEP_TIME_MS);
	}
}
/* #################### END LED #################### */

/* #################### START SERVO #################### */
enum direction {
	DOWN,
	UP,
};

void servo(void *id, void *unused1, void *unused2)
{
	ARG_UNUSED(unused1);
	ARG_UNUSED(unused2);
	int my_id = POINTER_TO_INT(id);

	const struct device *pwm;
	uint32_t pulse_width = MIN_PULSE_USEC;
	enum direction dir = UP;
	int ret;

	printk("Beginning execution; thread data is %d\n", my_id);
	k_msleep(200);

	pwm = device_get_binding(PWM_LABEL);
	if (!pwm) {
		printk("Error: didn't find %s device\n", PWM_LABEL);
		return;
	}

	while (1) {
		k_mutex_lock(&cliblock, K_FOREVER);
		printk("Thread %d \n", my_id);

		ret = pwm_pin_set_usec(pwm, 0, PERIOD_USEC, pulse_width, 0);
		if (ret < 0) {
			printk("Error %d: failed to set pulse width\n", ret);
			return;
		}

		if (dir == DOWN) {
			if (pulse_width <= MIN_PULSE_USEC) {
				dir = UP;
				pulse_width = MIN_PULSE_USEC;
			} else {
				pulse_width -= STEP_USEC;
			}
		} else {
			pulse_width += STEP_USEC;

			if (pulse_width >= MAX_PULSE_USEC) {
				dir = DOWN;
				pulse_width = MAX_PULSE_USEC;
			}
		}
        printk("PWM: %d\n", pulse_width);
		k_mutex_unlock(&cliblock);
		k_sleep(K_SECONDS(1));
	}
}
/* #################### END SERVO #################### */

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
	/* k_thread_create(&threads[0], &stacks[0][0], STACK_SIZE, */
	/* 		philosopher, INT_TO_POINTER(0), NULL, NULL, */
	/* 		0, K_USER, K_FOREVER); */
	k_thread_create(&threads[0], &stacks[0][0], STACK_SIZE,
			servo, INT_TO_POINTER(0), NULL, NULL,
			0, K_USER, K_FOREVER);
	
	k_object_access_grant(&cliblock, &threads[0]);
	k_object_access_grant(&cliblock, &threads[1]);
	
	k_thread_start(&threads[0]);
	
	//Crear hilo 1	
	k_thread_create(&threads[1], &stacks[1][0], STACK_SIZE,
		blinkLed, INT_TO_POINTER(1), NULL, NULL,
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
