#include "sensores.h"


void init_sensors(void){
	BSP_PSENSOR_Init();
}



void Pressure_Test(void){
	float press_value=0.;
	press_value= BSP_PSENSOR_ReadPressure();
	printf("Presion: %.2f mBar\r\n", press_value);
}
