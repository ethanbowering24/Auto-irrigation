#include <driver/adc.h>

/*---------------------------------------------Settings for soil zones---------------------------------------------*/
#define SOIL_SAMPLE_SIZE 500
#define NUM_ZONES 1
#define MAX_NUM_ZONES 4 

#define SOIL_SENSOR_0 ADC1_CHANNEL_0 //GPIO 36
#define SOIL_VALVE_0 10

#define SOIL_SENSOR_1 ADC1_CHANNEL_3 //GPIO 39
#define SOIL_VALVE_1 10

#define SOIL_SENSOR_2 ADC1_CHANNEL_6 //GPIO 34
#define SOIL_VALVE_2 10

#define SOIL_SENSOR_3 ADC1_CHANNEL_7 //GPIO 35
#define SOIL_VALVE_3 10


/*-----------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------Settings for SHT30 Sensor--------------------------------------------*/
#define USE_SHT30 1
/*-----------------------------------------------------------------------------------------------------------------*/


