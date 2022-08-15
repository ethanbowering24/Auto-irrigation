#include "settings.h"

void readSoilMoisture(void *); //declares function found in
void moistenSoil(void *);

extern int pinNums[MAX_NUM_ZONES][2];

typedef struct
{
    TaskHandle_t soilMoistureHandle;
    int soilMoisture;
    int sensorPin;
    int valvePin;

} zone_t;

extern zone_t zones[NUM_ZONES];
