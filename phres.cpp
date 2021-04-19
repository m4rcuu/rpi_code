#include "inc/phres.hpp"
#include <wiringPi.h>

Phres::Phres(const int _ledPin, const int _phresChanel, ADC *_adc) : ledPin(_ledPin),
                                                                           phresChanel(_phresChanel),
                                                                           adc(_adc)
{
    pinMode(ledPin, OUTPUT);
}

Phres::~Phres()
{
    this->ledOff();
}

void Phres::update()
{
    if (adc->getAnalog(phresChanel) < 300)
    {
        this->ledOn();
    }
    else
    {
        this->ledOff();
    }
}

void Phres::ledOn()
{
    digitalWrite(ledPin, HIGH);
}

void Phres::ledOff()
{
    digitalWrite(ledPin, LOW);
}