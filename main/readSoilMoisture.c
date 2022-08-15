#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soilZones.h" //soilZones.h includes settings.h which includes adc.h

void readSoilMoisture(void *zoneParam)
{
    zone_t *zone = (zone_t *)zoneParam; //cast void pointer to zone structure pointer

    static const char *TAG = "adc1"; //declare tag for log
    int reading = 0; //int to store readings
    int sum = 0; //int to store sum of readings

    //ADC setup
    ESP_LOGD(TAG, "starting ADC1");
    adc1_config_width(ADC_WIDTH_9Bit); //12 bits gives large fluctuations and I don't believe that level of precision is needed anyways.
    adc1_config_channel_atten(zone->sensorPin, ADC_ATTEN_11db);

    //Read soil moisture
    for (int i = 0; i < SOIL_SAMPLE_SIZE; i++)
    {
        reading = adc1_get_raw(zone->sensorPin);
        ESP_LOGD(TAG, "reading is: %d", reading);
        sum += reading;

        vTaskDelay(10/portTICK_PERIOD_MS);
    }
    
    //return average and delete
    //*(int *)ptrToSoilMoisture = sum/SOIL_SAMPLE_SIZE;
    zone->soilMoisture = sum/SOIL_SAMPLE_SIZE;

    vTaskDelete(NULL);
}