#include <stdio.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soilZones.h"

void app_main(void)
{   
    //array that holds values of physical pins on ESP board and watering threshold, defined in settings.h
    int zoneValues[MAX_NUM_ZONES][3] = {
        {SOIL_SENSOR_0, SOIL_VALVE_0, WATERING_THRESHOLD_0},
        {SOIL_SENSOR_1, SOIL_VALVE_1, WATERING_THRESHOLD_1},
        {SOIL_SENSOR_2, SOIL_VALVE_2, WATERING_THRESHOLD_2},
        {SOIL_SENSOR_3, SOIL_VALVE_3, WATERING_THRESHOLD_3}
    };

    //zone initialization
    zone_t zones[NUM_ZONES];
    for (int i = 0; i < NUM_ZONES; i++)
    {
        zones[i].soilMoistureHandle = NULL;
        zones[i].soilMoisture = 0;
        zones[i].sensorPin = zoneValues[i][0];
        zones[i].valvePin = zoneValues[i][1];
        zones[i].wateringThreshold = zoneValues[i][2];
        zones[i].zoneEnabled = 1;
        snprintf(zones[i].pcName, 18, "readSoilMoisture%c", i);
    }

    //start logging and read soil moisture test
    static const char *TAG = "main";
    ESP_LOGI(TAG, "Hello from main");

    while (1)
    {
        ESP_LOGI(TAG, "Soil moisture: %d", zones[0].soilMoisture);

        xTaskCreate(
            readSoilMoisture,
            zones[0].pcName,
            4096,
            &(zones[0]),
            10,
            &(zones[0].soilMoistureHandle)
        );
        
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}