#include "inc/cmanipulation.hpp"
#include "inc/adc.hpp"
#include "inc/dcmotors.hpp"
#include "inc/buzzer.hpp"
#include "inc/phres.hpp"
#include "inc/servo.hpp"
#include <wiringPi.h>
#include <iostream>

int main()
{
    echoOff();
    wiringPiSetup();

    //peripheral initialization
    DcMotors motors(8, 9, 0, 2, 7, 3);
    ADC adc(100, 0);
    Servo servo(5, 15);
    Phres phres(4, 4, &adc);
    Buzzer buzzer(1);

    //sound signal
    buzzer.play();
    delay(2000);
    buzzer.stop();

    //program loop
    int c = '\0';

    while (c != 27)
    {
        phres.update();
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
                motors.rotateLeft(50);
                break;
            case 'e':
                motors.rotateRight(50);
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
            case 'k':
                servo.rotate(-1);
                std::cout << servo.getRotation() << "\n";
                break;
            case 'l':
                servo.rotate(1);
                std::cout << servo.getRotation() << "\n";
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