#include <esp_log.h>
#include <math.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "include/settings.h"
#include "include/soilZones.h"

#ifdef SHT30_ENABLE

    #include "include/localWeather.h"

#endif

#if NUM_ZONES < 1
    #error "You must have at least one zone setup"
#elif NUM_ZONES > 4
    #error "This program only supports up to 4 zones, make sure to add more yourself and remove this compilation guard"
#endif

void app_main(void)
{   
    #if NUM_ZONES == 1
        #define BIT_MASK (1ULL<<SOIL_VALVE_0)
        
        int zoneValues[NUM_ZONES][3] = {
            {SOIL_SENSOR_0, SOIL_VALVE_0, WATERING_THRESHOLD_0}
        };

    #elif NUM_ZONES == 2
        #define BIT_MASK (1ULL<<SOIL_VALVE_0) | (1ULL<<SOIL_VALVE_1)

        int zoneValues[NUM_ZONES][3] = {
            {SOIL_SENSOR_0, SOIL_VALVE_0, WATERING_THRESHOLD_0},
            {SOIL_SENSOR_1, SOIL_VALVE_1, WATERING_THRESHOLD_1}
        };

    #elif NUM_ZONES == 3
        #define BIT_MASK (1ULL<<SOIL_VALVE_0) | (1ULL<<SOIL_VALVE_1) | (1ULL<<SOIL_VALVE_2)

        int zoneValues[NUM_ZONES][3] = {
            {SOIL_SENSOR_0, SOIL_VALVE_0, WATERING_THRESHOLD_0},
            {SOIL_SENSOR_1, SOIL_VALVE_1, WATERING_THRESHOLD_1},
            {SOIL_SENSOR_2, SOIL_VALVE_2, WATERING_THRESHOLD_2}
            };

    #elif NUM_ZONES == 4
        #define BIT_MASK (1ULL<<SOIL_VALVE_0) | (1ULL<<SOIL_VALVE_1) | (1ULL<<SOIL_VALVE_2) | (1ULL<<SOIL_VALVE_3)

        int zoneValues[NUM_ZONES][3] = {
            {SOIL_SENSOR_0, SOIL_VALVE_0, WATERING_THRESHOLD_0},
            {SOIL_SENSOR_1, SOIL_VALVE_1, WATERING_THRESHOLD_1},
            {SOIL_SENSOR_2, SOIL_VALVE_2, WATERING_THRESHOLD_2},
            {SOIL_SENSOR_3, SOIL_VALVE_3, WATERING_THRESHOLD_3}
        };
    #endif

    gpio_config_t output_config;
    output_config.pin_bit_mask = BIT_MASK;

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

    #ifdef SHT30_ENABLE

        localWeather_t localWeather;
        localWeather.localHumid = 0;
        localWeather.localTemp = 0;

    #endif

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