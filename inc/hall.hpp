#pragma once

#include "adc.hpp"

class Hall
{
private:
    int hallChanel;
    ADC *adc;

public:
    Hall(const int _hallPin, ADC *_adc);
    int getValue();
};