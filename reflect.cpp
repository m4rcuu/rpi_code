#include "inc/reflect.hpp"
#include <wiringPi.h>

Reflect::Reflect(const int _reflectPin, ADC *_adc) : reflectChanel(_reflectPin),
                                            adc(_adc)
{
}

int Reflect::getValue()
{
    return adc->getAnalog(reflectChanel);
}