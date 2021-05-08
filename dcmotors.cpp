#include "inc/dcmotors.hpp"
#include <wiringPi.h>
#include <softPwm.h>

DcMotors::DcMotors(const int _i1, const int _i2, const int _i3,
                   const int _i4, const int _e1, const int _e2) : input1(_i1),
                                                                  input2(_i2),
                                                                  input3(_i3),
                                                                  input4(_i4),
                                                                  enable1(_e1),
                                                                  enable2(_e2)
{
    this->motorInit();
}

DcMotors::~DcMotors()
{
    this->breaking();
}

void DcMotors::motorInit()
{
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(input3, OUTPUT);
    pinMode(input4, OUTPUT);

    digitalWrite(input1, 0);
    digitalWrite(input2, 0);
    digitalWrite(input3, 0);
    digitalWrite(input4, 0);

    softPwmCreate(enable1, 0, 100);
    softPwmCreate(enable2, 0, 100);
}

void DcMotors::ride(const int _chanel, const int _pwm)
{
    softPwmWrite(_chanel, _pwm);
}

void DcMotors::changeInputs(const bool _i1, const bool _i2, const bool _i3, const bool _i4)
{
    digitalWrite(input1, _i1);
    digitalWrite(input2, _i2);
    digitalWrite(input3, _i3);
    digitalWrite(input4, _i4);
}

void DcMotors::goStraight(const int _pwm)
{
    this->changeInputs(0, 1, 0, 1);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::goBack(const int _pwm)
{
    this->changeInputs(1, 0, 1, 0);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::rotateRight(const int _pwm)
{
    this->changeInputs(0, 1, 1, 0);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::rotateLeft(const int _pwm)
{
    this->changeInputs(1, 0, 0, 1);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::turnRight(const int _pwm)
{
    this->changeInputs(0, 1, 0, 0);
    this->ride(enable1, _pwm);
    this->ride(enable2, 0);
}

void DcMotors::turnLeft(const int _pwm)
{
    this->changeInputs(0, 0, 0, 1);
    this->ride(enable1, 0);
    this->ride(enable2, _pwm);
}

void DcMotors::breaking()
{
    this->ride(enable1, 0);
    this->ride(enable2, 0);
    this->changeInputs(0, 0, 0, 0);
}

void DcMotors::instantBreaking()
{
    this->ride(enable1, 0);
    this->ride(enable2, 0);
    this->changeInputs(1, 1, 1, 1);
}