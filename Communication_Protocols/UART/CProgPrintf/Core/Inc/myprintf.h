/*
 * myprintf.h
 *
 *  Created on: Oct 19, 2024
 *      Author: Diobedot
 */

#ifndef INC_MYPRINTF_H_
#define INC_MYPRINTF_H_

#include "stm32f1xx_hal.h"

void RetargetInit(UART_HandleTypeDef *huart);

int _write(int fd, char* ptr, int len);

#endif /* INC_MYPRINTF_H_ */
