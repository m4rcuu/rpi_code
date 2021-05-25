#pragma once

#include "adc.hpp"

class Reflect
{
private:
    int reflectChanel;
    ADC *adc;

public:
    Reflect(const int _reflectPin, ADC *_adc);
    int getValue();
};