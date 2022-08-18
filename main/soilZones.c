#include "include/soilZones.h" 
#include "include/settings.h"
#include <esp_log.h>
#include <driver/adc.h>
#include <driver/gpio.h>

void readSoilMoisture(void *voidZonePtr)
{
    zone_t *zonePtr = (zone_t *)voidZonePtr; //cast void pointer to zone structure pointer

    static const char *TAG = "adc1"; 
    int reading = 0; 
    int sum = 0; 

    //ADC setup
    ESP_LOGD(TAG, "starting ADC1");
    adc1_config_width(ADC_WIDTH_9Bit); //12 bits gives large fluctuations and I don't believe that level of precision is needed anyways.
    adc1_config_channel_atten(zonePtr->sensorPin, ADC_ATTEN_11db);

    //Read soil moisture
    for (int i = 0; i < SOIL_SAMPLE_SIZE; i++)
    {
        reading = adc1_get_raw(zonePtr->sensorPin); //make this more efficient by removing the reading variable and just writing sum += adc1_get_raw(zonePtr->sensorPin);
        ESP_LOGD(TAG, "reading is: %d", reading);   
        sum += reading;

        vTaskDelay(10/portTICK_PERIOD_MS);
    }
    
    //return average and delete
    zonePtr->soilMoisture = sum/SOIL_SAMPLE_SIZE;
    vTaskDelete(NULL);
}

void moistenSoil(void *voidZonePtr){
    
}