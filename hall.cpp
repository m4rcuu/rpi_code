#include "inc/hall.hpp"
#include <wiringPi.h>

Hall::Hall(const int _hallPin, ADC *_adc) : hallChanel(_hallPin),
                                            adc(_adc)
{
}

int Hall::getValue()
{
    return adc->getAnalog(hallChanel);
}