#pragma once

class Buzzer
{
private:
    int pin;

public:
    Buzzer(const int _pin);
    ~Buzzer();
    void play();
    void stop();
};