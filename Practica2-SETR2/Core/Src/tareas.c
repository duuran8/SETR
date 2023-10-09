#include "tareas.h"

void CreateLedTask(){
	//puntero a la funcion, nombre, tamaño de pila, parametro de tarea, numero de prioridad, handle de tarea
	xTaskCreate(LedToggleTask, "LedToggleTask", 128, NULL, NULL, NULL);
}


void LedToggleTask(void *pArg){
	while(1){
		for(;;){
			led_toggle(0);
			vTaskDelay(1000);
		}
	}
}

// misma funcion que el ejemplo pero el modo de parpadeo depende del parametro
void CreateLedTaskParam(int param){
	xTaskCreate(LedToggleTaskParam, "LedToggleTaskParam", 128, param, 1, NULL);
	}

void LedToggleTaskParam(void *pArg){
	while(1){
		int p = (int *) pArg;
		for(;;){
			led_toggle(p);
			vTaskDelay(500);
		}
	}
}

void CreateLedTaskChain(int param){
	xTaskCreate(LedTaskChain, "LedTaskChain", 128, param, 1, NULL);
}

void LedTaskChain(void *pArg){
	while(1){
		int p = (int *) pArg;
		for(int i=0;i<5;i++){
				led_toggle(p);
				vTaskDelay(500);
			}
		CreateLedTaskChain((p=p+1)%4);
		vTaskDelete(NULL);
	}
}
