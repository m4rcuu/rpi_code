#include "inc/servo.hpp"
#include <wiringPi.h>
#include <softPwm.h>

Servo::Servo(const int _pinPWM, const int _rotation) : pinPWM(_pinPWM),
                                                       rotation(_rotation)
{
    softPwmCreate(pinPWM, 0, 30);
    softPwmWrite(pinPWM, rotation);
}

Servo::~Servo()
{
    softPwmWrite(pinPWM, 15);
}

void Servo::rotate(const int _rotation)
{
    rotation += _rotation;

    if (rotation < 1)
    {
        rotation = 1;
    }
    else if (rotation > 29)
    {
        rotation = 29;
    }

    softPwmWrite(pinPWM, rotation);
}

const int Servo::getRotation()
{
    return rotation;
}