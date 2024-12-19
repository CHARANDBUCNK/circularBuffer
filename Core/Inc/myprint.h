/*
 * myprint.h
 *
 *  Created on: Oct 24, 2024
 *      Author: Lenovo
 */

#ifndef INC_MYPRINT_H_
#define INC_MYPRINT_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

void vprint(UART_HandleTypeDef* pUsart , const char *fmt, va_list argp);

void my_printf(UART_HandleTypeDef* pUsart, const char *fmt, ...); // custom printf() function

#endif /* INC_MYPRINT_H_ */
