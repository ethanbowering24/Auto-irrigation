#include <stdio.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void readSoilMoisture(void *); 

static const char *TAG = "main";

TaskHandle_t soilMoistureHandle = NULL;

int soilMoisture = 0;

void app_main(void)
{
    ESP_LOGI(TAG, "Hello from main");

    while (1)
    {
        ESP_LOGI(TAG, "Soil moisture: %d", soilMoisture);
    
        xTaskCreate(
            readSoilMoisture,
            "readSoilMoisture",
            4096,
            &soilMoisture,
            10,
            &soilMoistureHandle
        );

        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
