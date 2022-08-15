#include "settings.h"

void readSoilMoisture(void *); 
void moistenSoil(void *);

typedef struct
{
    TaskHandle_t soilMoistureHandle;
    int soilMoisture;
    int sensorPin;
    int valvePin;
    int wateringThreshold;
    char pcName[28];
    bool zoneEnabled;

} zone_t;

extern zone_t zones[NUM_ZONES];
extern int zoneValues[MAX_NUM_ZONES][3];