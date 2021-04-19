#include "inc/dcmotors.hpp"
#include <wiringPi.h>
#include <softPwm.h>

DcMotors::DcMotors(int _input1, int _input2, int _input3, int _input4, int _enable1, int _enable2) : input1(_input1),
                                                                                                     input2(_input2),
                                                                                                     input3(_input3),
                                                                                                     input4(_input4),
                                                                                                     enable1(_enable1),
                                                                                                     enable2(_enable2)
{
    this->motor1init();
    this->motor2init();
}

DcMotors::~DcMotors()
{
    this->breaking();
}

void DcMotors::motor1init()
{
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    softPwmCreate(enable1, 0, 100);
}
void DcMotors::motor2init()
{
    pinMode(input3, OUTPUT);
    pinMode(input4, OUTPUT);
    softPwmCreate(enable2, 0, 100);
}

void DcMotors::ride(const int _chanel, const int _pwm)
{
    softPwmWrite(_chanel, _pwm);
}

void DcMotors::changeStateM1(bool _chanel1, bool _chanel2)
{
    pinMode(input1, _chanel1);
    pinMode(input2, _chanel2);
}

void DcMotors::changeStateM2(bool _chanel1, bool _chanel2)
{
    pinMode(input3, _chanel1);
    pinMode(input4, _chanel2);
}

void DcMotors::goStraight(const int _pwm)
{
    this->changeStateM1(0, 1);
    this->changeStateM2(0, 1);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::goBack(const int _pwm)
{
    this->changeStateM1(1, 0);
    this->changeStateM2(1, 0);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::turnRightInPlace(const int _pwm)
{
    this->changeStateM1(0, 1);
    this->changeStateM2(1, 0);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::turnLeftInPlace(const int _pwm)
{
    this->changeStateM1(1, 0);
    this->changeStateM2(0, 1);
    this->ride(enable1, _pwm);
    this->ride(enable2, _pwm);
}

void DcMotors::turnRight(const int _pwm)
{
    this->changeStateM1(0, 1);
    this->changeStateM2(0, 0);
    this->ride(enable1, _pwm);
    this->ride(enable2, 0);
}

void DcMotors::turnLeft(const int _pwm)
{
    this->changeStateM1(0, 0);
    this->changeStateM2(0, 1);
    this->ride(enable1, 0);
    this->ride(enable2, _pwm);
}

void DcMotors::breaking()
{
    this->ride(enable1, 0);
    this->ride(enable2, 0);
    this->changeStateM1(0, 0);
    this->changeStateM2(0, 0);
}

void DcMotors::instantBreaking()
{
    this->ride(enable1, 0);
    this->ride(enable2, 0);
    this->changeStateM1(1, 1);
    this->changeStateM2(1, 1);
}