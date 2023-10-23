#include "main.h"

#include "../../BSP/stm32l475e_iot01.h"
#include "../../BSP/stm32l475e_iot01_accelero.h"
#include "../../BSP/stm32l475e_iot01_magneto.h"
#include "../../BSP/stm32l475e_iot01_gyro.h"
#include "../../BSP/stm32l475e_iot01_tsensor.h"
#include "../../BSP/stm32l475e_iot01_psensor.h"
#include "../../BSP/stm32l475e_iot01_hsensor.h"
#include "../../BSP/stm32l475e_iot01_qspi.h"
#include <stdio.h>

//Funciones

void init_sensors(void);
void Temperature_Test(void);
void Humidity_Test(void);
void Pressure_Test(void);
void Gyro_Test(void);
void Magneto_Test(void);
void Accelero_Test(void);
