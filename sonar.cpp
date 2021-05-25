#include "inc/sonar.hpp"
#include <wiringPi.h>

Sonar::Sonar(const int _triggerPin, const int _echoPin) : triggerPin(_triggerPin),
                                                          echoPin(_echoPin)
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(triggerPin, LOW);
}

Sonar::~Sonar()
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    digitalWrite(echoPin, LOW);
}

void Sonar::recordPulseLength()
{
    startTimeUsec = micros();
    while (digitalRead(echoPin) == HIGH)
        ;
    endTimeUsec = micros();
}

double Sonar::getDistance(const int _timeout = 3000)
{
    delay(10);

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    timeNow = micros();

    while (digitalRead(echoPin) == LOW && micros() - timeNow < _timeout)
        ;
    this->recordPulseLength();

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distance = 100 * ((travelTimeUsec / 1000000.0) * 340.29) / 2;

    return distance;
}