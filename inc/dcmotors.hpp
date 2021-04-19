#pragma once

class DcMotors
{
private:
    int input1;
    int input2;
    int input3;
    int input4;
    int enable1;
    int enable2;
    void motor1init();
    void motor2init();
    void ride(const int _chanel, const int _pwm);
    void changeStateM1(const bool _chanel1, const bool _chanel2);
    void changeStateM2(const bool _chanel1, const bool _chanel2);

public:
    DcMotors(const int _input1, const int _input2, const int _input3, const int _input4, const int _enable1, const int _enable2);
    ~DcMotors();
    void goStraight(const int _pwm);
    void goBack(const int _pwm);
    void turnRightInPlace(const int _pwm);
    void turnLeftInPlace(const int _pwm);
    void turnRight(const int _pwm);
    void turnLeft(const int _pwm);
    void breaking();
    void instantBreaking();
};