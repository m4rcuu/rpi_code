#pragma once

class Sonar
{
private:
    int triggerPin;
    int echoPin;
    volatile long startTimeUsec;
    volatile long endTimeUsec;
    double distance;
    long travelTimeUsec;
    long timeNow;
    void recordPulseLength();

    public:
    Sonar(const int _triggerPin, const int _echoPin);
    ~Sonar();
    double getDistance(const int _timeout=3000);
};