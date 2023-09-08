#include "temperature_conversor.h"
#include <stdio.h>

float convert_celsius_to_kelvin(float temperature){
    temperature += 273.15;
    return temperature;
}

float convert_celsius_to_fahrenheit(float temperature){
    temperature = 9*temperature/5;
    temperature += 32;
    return temperature;
}

float convert_kelvin_to_celsius(float temperature){
    temperature -= 273.15;
    return temperature;
}

float convert_kelvin_to_fahrenheit(float temperature){
    temperature -= 273.15;
    temperature = 9*temperature/5;
    temperature += 32;
    return temperature;
}

float convert_fahrenheit_to_celsius(float temperature){
    temperature -= 32;
    temperature = 5*temperature/9;
    return temperature;
}

float convert_fahrenheit_to_kelvin(float temperature){
    temperature -= 32;
    temperature = 5*temperature/9;
    temperature += 273.15; 
    return temperature;
}

float convert_temperature(float temperature, float convert_func(float temperature)){
    temperature = convert_func(temperature);
    return temperature;
}