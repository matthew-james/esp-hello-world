/*
The MIT License (MIT)
Copyright (c) 2014 Matt Callow
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
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
