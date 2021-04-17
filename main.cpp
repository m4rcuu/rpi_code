#include "inc/cmanipulation.hpp"
#include "inc/adc.hpp"
#include "inc/dcmotors.hpp"
#include <iostream>

int main()
{
    echoOff();
    wiringPiSetup();

    DcMotors motors(8, 9, 0, 2, 7, 3);
    ADC adc(100, 0);

    int c = '\0';

    while (c != 'q')
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
            case 'b':
                motors.breaking()
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