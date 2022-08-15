#pragma once

/*---------------------------------------------Settings for soil zones---------------------------------------------*/
//You must wire up your zone sensors sequentially starting from 0.
#define SOIL_SAMPLE_SIZE 500
#define NUM_ZONES 1
#define MAX_NUM_ZONES 4 //You can set up to 4 zones (0-3) without modifying code.

#define SOIL_SENSOR_0 ADC1_CHANNEL_0 //GPIO 36
#define SOIL_VALVE_0 10
#define WATERING_THRESHOLD_0 50

#define SOIL_SENSOR_1 ADC1_CHANNEL_3 //GPIO 39
#define SOIL_VALVE_1 10
#define WATERING_THRESHOLD_1 50

#define SOIL_SENSOR_2 ADC1_CHANNEL_6 //GPIO 34
#define SOIL_VALVE_2 10
#define WATERING_THRESHOLD_2 50

#define SOIL_SENSOR_3 ADC1_CHANNEL_7 //GPIO 35
#define SOIL_VALVE_3 10
#define WATERING_THRESHOLD_3 50
/*-----------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------Settings for SHT30 Sensor--------------------------------------------*/
#define SHT30_ENABLE 
/*-----------------------------------------------------------------------------------------------------------------*/
