/*
 * led_toggle.c
 *
 *  Created on: Oct 2, 2023
 *      Author: julianduran
 */
#include "led_toggle.h"


void led_toggle(uint8_t led) {

	switch (led) {
		case 0:
		{
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			HAL_GPIO_TogglePin(GPIOC, LED3_WIFI__LED4_BLE_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_3_Pin);
		}	break;
		case 1:
			HAL_GPIO_WritePin(GPIOC, LED3_WIFI__LED4_BLE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			break;
		case 2:
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(GPIOC, LED3_WIFI__LED4_BLE_Pin);
			break;
		case 3:
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOC, LED3_WIFI__LED4_BLE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(GPIOA, LED_3_Pin);
		default:
			break;
		}
}



