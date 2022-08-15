#include <esp_log.h>
#include "include/soilZones.h"

#if !NUM_ZONES
    #error "You must have at least one zone setup"
#endif

void app_main(void)
{   
    //zone initialization
    zone_t zones[NUM_ZONES];
    
    #if NUM_ZONES == 1
        zones[0].soilMoistureHandle = NULL;
        zones[0].soilMoisture = 0;
        zones[0].sensorPin = SOIL_SENSOR_0;
        zones[0].valvePin = SOIL_VALVE_0;
        zones[0].wateringThreshold = WATERING_THRESHOLD_0;
        zones[0].zoneEnabled = 1;
        snprintf(zones[0].pcName, 18, "readSoilMoisture0");
    #endif

    #if NUM_ZONES == 2
        zones[0].soilMoistureHandle = NULL;
        zones[0].soilMoisture = 0;
        zones[0].sensorPin = SOIL_SENSOR_0;
        zones[0].valvePin = SOIL_VALVE_0;
        zones[0].wateringThreshold = WATERING_THRESHOLD_0;
        zones[0].zoneEnabled = 1;
        snprintf(zones[0].pcName, 18, "readSoilMoisture0");

        zones[1].soilMoistureHandle = NULL;
        zones[1].soilMoisture = 1;
        zones[1].sensorPin = SOIL_SENSOR_1;
        zones[1].valvePin = SOIL_VALVE_1;
        zones[1].wateringThreshold = WATERING_THRESHOLD_1;
        zones[1].zoneEnabled = 1;
        snprintf(zones[1].pcName, 18, "readSoilMoisture1");
    #endif

    #if NUM_ZONES == 3
        zones[0].soilMoistureHandle = NULL;
        zones[0].soilMoisture = 0;
        zones[0].sensorPin = SOIL_SENSOR_0;
        zones[0].valvePin = SOIL_VALVE_0;
        zones[0].wateringThreshold = WATERING_THRESHOLD_0;
        zones[0].zoneEnabled = 1;
        snprintf(zones[0].pcName, 18, "readSoilMoisture0");

        zones[1].soilMoistureHandle = NULL;
        zones[1].soilMoisture = 1;
        zones[1].sensorPin = SOIL_SENSOR_1;
        zones[1].valvePin = SOIL_VALVE_1;
        zones[1].wateringThreshold = WATERING_THRESHOLD_1;
        zones[1].zoneEnabled = 1;
        snprintf(zones[1].pcName, 18, "readSoilMoisture1");

        zones[2].soilMoistureHandle = NULL;
        zones[2].soilMoisture = 2;
        zones[2].sensorPin = SOIL_SENSOR_2;
        zones[2].valvePin = SOIL_VALVE_2;
        zones[2].wateringThreshold = WATERING_THRESHOLD_2;
        zones[2].zoneEnabled = 2;
        snprintf(zones[2].pcName, 18, "readSoilMoisture2");
    #endif

    #if NUM_ZONES == 4
        zones[0].soilMoistureHandle = NULL;
        zones[0].soilMoisture = 0;
        zones[0].sensorPin = SOIL_SENSOR_0;
        zones[0].valvePin = SOIL_VALVE_0;
        zones[0].wateringThreshold = WATERING_THRESHOLD_0;
        zones[0].zoneEnabled = 1;
        snprintf(zones[0].pcName, 18, "readSoilMoisture0");

        zones[1].soilMoistureHandle = NULL;
        zones[1].soilMoisture = 1;
        zones[1].sensorPin = SOIL_SENSOR_1;
        zones[1].valvePin = SOIL_VALVE_1;
        zones[1].wateringThreshold = WATERING_THRESHOLD_1;
        zones[1].zoneEnabled = 1;
        snprintf(zones[1].pcName, 18, "readSoilMoisture1");

        zones[2].soilMoistureHandle = NULL;
        zones[2].soilMoisture = 2;
        zones[2].sensorPin = SOIL_SENSOR_2;
        zones[2].valvePin = SOIL_VALVE_2;
        zones[2].wateringThreshold = WATERING_THRESHOLD_2;
        zones[2].zoneEnabled = 2;
        snprintf(zones[2].pcName, 18, "readSoilMoisture2");

        zones[3].soilMoistureHandle = NULL;
        zones[3].soilMoisture = 3;
        zones[3].sensorPin = SOIL_SENSOR_3;
        zones[3].valvePin = SOIL_VALVE_3;
        zones[3].wateringThreshold = WATERING_THRESHOLD_3;
        zones[3].zoneEnabled = 3;
        snprintf(zones[3].pcName, 18, "readSoilMoisture3");
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