/*
 * myprint.c
 *
 *  Created on: Oct 24, 2024
 *      Author: Lenovo
 */



#include "myprint.h"



void vprint(UART_HandleTypeDef* pUsart , const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string,fmt,argp)) // build string
    {
        HAL_UART_Transmit( pUsart, (uint8_t*)string, strlen(string), 0xffffff); // send message via UART
    }
}

void my_printf(UART_HandleTypeDef* pUsart, const char *fmt, ...) // custom printf() function
{
    va_list argp;
    va_start(argp, fmt);
    vprint( pUsart ,fmt, argp);
    va_end(argp);
}
