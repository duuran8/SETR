#include "SerialTask.h"

SemaphoreHandle_t xSemaphore;
QueueHandle_t xQueue;
char buf;

void CreateSerialObjects(void){
	xSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(xSemaphore);

	xQueue = xQueueCreate(16, sizeof(buf));
	HAL_UART_Receive_IT(&huart1,buf,sizeof(buf));
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

void HAL_UART_RxCptHandler(){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	BaseType_t xStatus = xQueueSend( xQueue, &buf,portMAX_DELAY);
	xStatus = xQueueSendFromISR(xQueue, &buf, &xHigherPriorityTaskWoken);
	HAL_UART_Receive_IT(&huart1,buf,sizeof(buf));

}
void CreatePrueba(){
	xTaskCreate(prueba, "prueba", 128, NULL, 1, NULL);
}
 void prueba(void *pArg){
	 while(1){
	 printf("Hola\r\n");
	 vTaskDelay(2500);
	 }
 }


