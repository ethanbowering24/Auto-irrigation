#pragma once

void checkLocalWeather(void *);

typedef struct
{
    int localTemp;
    int localHumid;
} localWeather_t;
