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
    void motorInit();
    void ride(const int _chanel, const int _pwm);
    void changeInputs(const bool _i1, const bool _i2, const bool _i3, const bool _i4);

public:
    DcMotors(const int _i1, const int _i2, const int _i3, const int _i4, const int _e1, const int _e2);
    ~DcMotors();
    void goStraight(const int _pwm);
    void goBack(const int _pwm);
    void rotateRight(const int _pwm);
    void rotateLeft(const int _pwm);
    void turnRight(const int _pwm);
    void turnLeft(const int _pwm);
    void breaking();
    void instantBreaking();
};