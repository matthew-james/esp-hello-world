#include "ets_sys.h"
#include "osapi.h"
#include "user_interface.h"
#include "gpio.h"
#include "driver/uart.h"

#define DELAY 1000 /* milliseconds */

extern int ets_uart_printf(const char *fmt, ...);

LOCAL os_timer_t hello_timer;

LOCAL void ICACHE_FLASH_ATTR

hello_cb(void *arg)
{
    ets_uart_printf("Hello World!\r\n");
}


void user_init(void)
{
    // Configure the UART
    uart_init(BIT_RATE_9600, BIT_RATE_9600);

    // Set up a timer to send the message
    os_timer_disarm(&hello_timer);
   
    os_timer_setfn(&hello_timer, (os_timer_func_t *)hello_cb, (void *)0);

    os_timer_arm(&hello_timer, DELAY, 1);
}