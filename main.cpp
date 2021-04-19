#include "inc/cmanipulation.hpp"
#include "inc/adc.hpp"
#include "inc/dcmotors.hpp"
#include "inc/buzzer.hpp"
#include <wiringPi.h>
#include <iostream>

int main()
{
    echoOff();
    wiringPiSetup();

    DcMotors motors(8, 9, 0, 2, 7, 3);
    ADC adc(100, 0);
    Buzzer buzzer(1);
    buzzer.play();
    delay(2000);
    buzzer.stop();

    int c = '\0';

    while (c != 27)
    {
        if (kbhit())
        {
            c = getchar();

            switch (c)
            {
            case 'w':
                motors.goStraight(50);
                break;
            case 's':
                motors.goBack(50);
                break;
            case 'a':
                motors.turnLeft(50);
                break;
            case 'd':
                motors.turnRight(50);
                break;
            case 'q':
                motors.turnLeftInPlace(50);
                break;
            case 'e':
                motors.turnRightInPlace(50);
                break;
            case 'b':
                motors.breaking();
                break;
            case 'n':
                motors.instantBreaking();
                break;
            case 'r':
                std::cout << adc.getAnalog(4) << "\n";
                break;
            default:
                std::cout << "key unknown\n";
                break;
            }

            std::cout << "got key " << c << "\n";
        }
    }
    echoOn();

    return 0;
}