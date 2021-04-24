#include "inc/servo.hpp"
#include <wiringPi.h>
#include <softPwm.h>

Servo::Servo(const int _pinPWM, const int _rotation) : pinPWM(_pinPWM),
                                                       rotation(_rotation)
{
    softPwmCreate(pinPWM, 0, 100);
    softPwmWrite(pinPWM, rotation);
}

Servo::~Servo()
{
    softPwmWrite(pinPWM, 50);
}

void Servo::rotate(const int _rotation)
{
    rotation += _rotation;

    if (rotation < 0)
    {
        rotation = 0;
    }
    else if (rotation > 100)
    {
        rotation = 100;
    }

    softPwmWrite(pinPWM, rotation);
}