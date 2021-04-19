#pragma once

#include "adc.hpp"

class Phres
{
private:
    int ledPin;
    int phresChanel;
    ADC *adc;
    void ledOn();
    void ledOff();

public:
    Phres(const int _ledPin, const int _phresChanel, ADC *_adc);
    ~Phres();
    void update();
};