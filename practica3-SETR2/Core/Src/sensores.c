#include "sensores.h"


void init_sensors(void){
	BSP_PSENSOR_Init();
	BSP_HSENSOR_Init();
	BSP_TSENSOR_Init();

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
