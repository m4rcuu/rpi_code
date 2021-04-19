#pragma once

class Buzzer
{
private:
    int pin;
    ~Buzzer();

public:
    Buzzer(const int _pin);
    void play();
    void stop();
};