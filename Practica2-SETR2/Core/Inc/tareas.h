#include "led_toggle.h"
#include "stm32l4xx_hal.h"

void CreateLedTask();
void LedToggleTask(void *pArg);
void CreateLedTaskParam(int param);
void LedToggleTaskParam(void *pArg);
void CreateLedTaskChain(int param);
void LedTaskChain(void *pArg);
