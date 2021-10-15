#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <irq.h>
#include <uart.h>
#include <console.h>
#include <generated/csr.h>

/* static void busy_wait1(unsigned int ds) */
/* { */
/* 	timer0_en_write(0); */
/* 	timer0_reload_write(0); */
/* 	timer0_load_write(CONFIG_CLOCK_FREQUENCY/10*ds); */
/* 	timer0_en_write(1); */
/* 	timer0_update_value_write(1); */
/* 	while(timer0_value_read()) timer0_update_value_write(1); */
/* } */

void leds(int);

static char *readstr(void)
{
	char c[2];
	static char s[64];
	static int ptr = 0;

	if(readchar_nonblock()) {
		c[0] = readchar();
		c[1] = 0;
		switch(c[0]) {
			case 0x7f:
			case 0x08:
				if(ptr > 0) {
					ptr--;
					putsnonl("\x08 \x08");
				}
				break;
			case 0x07:
				break;
			case '\r':
			case '\n':
				s[ptr] = 0x00;
				putsnonl("\n");
				ptr = 0;
				return s;
			default:
				if(ptr >= (sizeof(s) - 1))
					break;
				putsnonl(c);
				s[ptr] = c[0];
				ptr++;
				break;
		}
	}

	return NULL;
}

static char *get_token(char **str)
{
	char *c, *d;

	c = (char *)strchr(*str, ' ');
	if(c == NULL) {
		d = *str;
		*str = *str+strlen(*str);
		return d;
	}
	*c = 0;
	d = *str;
	*str = c+1;
	return d;
}

static void prompt(void)
{
	printf("RUNTIME>");
}

static void help(void)
{
	puts("Available commands:");
	puts("help                            - this command");
	puts("reboot                          - reboot CPU");
	/* puts("led                             - led test"); */
	puts("leds-on                            - leds test");
	puts("leds-off                            - leds test");
}

static void reboot(void)
{
	ctrl_reset_write(1);
}

/* static void led_test(void) */
/* { */
/* 	int i; */
/* 	printf("led_test...\n"); */
/* 	for(i=0; i<32; i++) { */
/* 		leds_out_write(i); */
/* 		busy_wait1(10); */
/* 	    printf("led_test... %d \n", i); */
/* 	} */
/* } */

void leds(int status)
{
   leds_out_write(status);
}

static void console_service(void)
{
	char *str;
	char *token;

	str = readstr();
	if(str == NULL) return;
	token = get_token(&str);
	if(strcmp(token, "help") == 0)
		help();
	else if(strcmp(token, "reboot") == 0)
		reboot();
	/* else if(strcmp(token, "led") == 0) */
	/* 	led_test(); */
	else if(strcmp(token, "leds-on") == 0)
		leds(2);   // 1 0
	else if(strcmp(token, "leds-off") == 0)
		leds(1);   // 0 1
	prompt();
}

int main(void)
{
	irq_setmask(0);
	irq_setie(1);
	uart_init();

	leds(2);   // 0 1
	puts("\nLab004 - CPU testing software built "__DATE__" "__TIME__"\n");
	help();
	prompt();

	while(1) {
		console_service();
	}

	return 0;
}
