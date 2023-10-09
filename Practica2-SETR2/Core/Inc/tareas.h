#include "FreeRTOS.h"
#include "task.h"

#include "led_toggle.h"
#include "stm32l4xx_hal.h"


void CreateLedTask();
void LedToggleTask(void *pArg);
void CreateLedTaskParam(int param);
void LedToggleTaskParam(void *pArg);
void CreateLedTaskChain(int param);
void LedTaskChain(void *pArg);
void CreateButtonTask();
void ButtonTask(void *pArg);
void CreateLedTaskNotify();
void LedTaskNotify();
