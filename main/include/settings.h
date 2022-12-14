#pragma once
#include <driver/adc.h>

/*---------------------------------------------Settings for soil zones---------------------------------------------*/
//You must wire up your zone sensors sequentially.
#define SOIL_SAMPLE_SIZE 500
#define NUM_ZONES 1
#define MAX_NUM_ZONES 4 

#define SOIL_SENSOR_0 ADC1_CHANNEL_0 //GPIO 36
#define SOIL_VALVE_0 GPIO_NUM_10
#define WATERING_THRESHOLD_0 50

#define SOIL_SENSOR_1 ADC1_CHANNEL_3 //GPIO 39
#define SOIL_VALVE_1 GPIO_NUM_11
#define WATERING_THRESHOLD_1 50

#define SOIL_SENSOR_2 ADC1_CHANNEL_6 //GPIO 34
#define SOIL_VALVE_2 GPIO_NUM_12
#define WATERING_THRESHOLD_2 50

#define SOIL_SENSOR_3 ADC1_CHANNEL_7 //GPIO 35
#define SOIL_VALVE_3 GPIO_NUM_13
#define WATERING_THRESHOLD_3 50

/*-----------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------Settings for SHT30 Sensor--------------------------------------------*/
#define SHT30_ENABLE 
/*-----------------------------------------------------------------------------------------------------------------*/
