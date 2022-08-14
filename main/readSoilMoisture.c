#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>
#include <driver/adc.h>


#define SOIL_SAMPLE_SIZE 500

void readSoilMoisture(void *ptrToSoilMoisture)
{
    static const char *TAG = "adc1"; //declare tag for log
    int reading = 0; //int to store readings
    int sum = 0; //int to store sum of readings

    //ADC setup
    ESP_LOGD(TAG, "starting ADC1");
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_11db);

    //Read soil moisture
    for (int i = 0; i < SOIL_SAMPLE_SIZE; i++)
    {
        reading = adc1_get_raw(ADC_CHANNEL_0);
        ESP_LOGD(TAG, "reading is: %d", reading);
        sum += reading;

        vTaskDelay(10/portTICK_PERIOD_MS);
    }
    
    //return average and delete
    *(int *)ptrToSoilMoisture = sum/SOIL_SAMPLE_SIZE;
    vTaskDelete(NULL);
}