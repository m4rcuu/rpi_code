#include "inc/buzzer.hpp"
#include <wiringPi.h>

Buzzer::Buzzer(const int _pin) : pin(_pin)
{
    pinMode(pin, OUTPUT);
}

Buzzer::~Buzzer()
{
    this->stop();
}

void Buzzer::play()
{
    digitalWrite(pin, HIGH);
}

void Buzzer::stop()
{
    digitalWrite(pin, LOW)
}