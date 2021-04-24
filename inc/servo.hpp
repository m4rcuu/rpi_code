#pragma once

class Servo
{
private:
    int pinPWM;
    int rotation;

public:
    Servo(const int _pinPWM, const int _rotation);
    ~Servo();
    void rotate(const int _rotation);
};