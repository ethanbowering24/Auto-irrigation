#pragma once

#include "include/settings.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void readSoilMoisture(void *); 
void moistenSoil(void *);

typedef struct
{
    TaskHandle_t soilMoistureHandle;
    int soilMoisture;
    int sensorPin;
    int valvePin;
    int wateringThreshold;
    bool zoneEnabled;
    char pcName[18];
} zone_t;

extern zone_t zones[NUM_ZONES];
extern int zoneValues[MAX_NUM_ZONES][3];