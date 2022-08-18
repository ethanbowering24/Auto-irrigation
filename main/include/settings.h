#pragma once
#include <driver/adc.h>
#include <driver/gpio.h>

/*---------------------------------------------Settings for soil zones---------------------------------------------*/
//You must connect your zone sensors sequentially (If NUM_ZONES = 3 you must use 0, 1 and 2 and not 0, 2 and 3).
#define NUM_ZONES 1
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

#define SOIL_SAMPLE_SIZE 500
/*-----------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------Settings for SHT30 sensor--------------------------------------------*/
#define SHT30_ENABLE 
/*-----------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------Settings for internet weather check---------------------------------------*/
#define INTERNET_ENABLE
/*-----------------------------------------------------------------------------------------------------------------*/