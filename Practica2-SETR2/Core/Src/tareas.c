#include "tareas.h"

void CreateLedTask(){
	//puntero a la funcion, nombre, tamaño de pila, parametro de tarea, numero de prioridad, handle de tarea
	xTaskCreate(LedToggleTask, "LedToggleTask", 128, NULL, 1, NULL);
}


void LedToggleTask(void *pArg){
	for(;;){
		led_toggle(0);
		vTaskDelay(1000);
	}
}


void CreateLedTaskParam(){
	xTaskCreate(LedToggleTaskParam, "LedToggleTaskParam", 128, 3, 1, NULL);
	}

void LedToggleTaskParam(void *pArg){
	int p = (int *) pArg;
	for(;;){
		led_toggle(p);
		vTaskDelay(1000);
	}
}
