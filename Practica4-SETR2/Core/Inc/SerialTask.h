#pragma once
#include "FreeRTOS.h"
#include "main.h"
#include "semphr.h"

extern UART_HandleTypeDef huart1;

void CreateSerialObjects(void);
void SerialSendByte(char data);
