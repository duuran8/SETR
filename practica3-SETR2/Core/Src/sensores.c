#include "sensores.h"


void init_sensors(void){
	BSP_PSENSOR_Init();
	BSP_HSENSOR_Init();
	BSP_TSENSOR_Init();
	BSP_MAGNETO_Init();
	BSP_ACCELERO_Init();
}



void Pressure_Test(void){
	float press_value=0.;
	press_value= BSP_PSENSOR_ReadPressure();
	printf("Presion: %.2f mBar\r\n", press_value);
}


void Humidity_Test(void){
	float humidity_value=0.;
	humidity_value= BSP_HSENSOR_ReadHumidity();
	printf("Humedad: %.2f %%\r\n", humidity_value);
}

void Temperature_Test(void){
	float temperature_value=0.;
	temperature_value= BSP_TSENSOR_ReadTemp();
	printf("Temperatura: %.2f ºC\r\n", temperature_value);
}

void Magneto_Test(){
	int16_t pData[3]={0};
	BSP_MAGNETO_GetXYZ(pData);
	printf("Magneto_X: %d \r\n Magneto_Y: %d \r\n Magneto_Z: %d \r\n", pData[0], pData[1], pData[2]);
}

void Accelero_Test(){
	int16_t pData[3]={0};
	BSP_ACCELERO_AccGetXYZ(pData);
	printf("Accelero_X: %d \r\n Accelero_Y: %d \r\n Accelero_Z: %d \r\n", pData[0], pData[1], pData[2]);
}

