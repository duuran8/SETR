#include "SerialTask.h"

SemaphoreHandle_t xSemaphore;

void CreateSerialObjects(void){
	xSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(xSemaphore);
}
void SerialSendByte(char data){
	BaseType_t status = xSemaphoreTake(xSemaphore, -1);
	HAL_UART_Transmit_IT(&huart1, &data,1);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef* huart){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);

    // Si la función despierta una tarea de mayor prioridad, notificar al planificador
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}
 void prueba(void){
	 printf("Hola amigo");

 }
