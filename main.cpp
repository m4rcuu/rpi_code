#include "inc/cmanipulation.hpp"
#include "inc/adc.hpp"
#include "inc/dcmotors.hpp"
#include "inc/buzzer.hpp"
#include "inc/phres.hpp"
#include "inc/servo.hpp"
#include "inc/sonar.hpp"
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
    Phres phres(15, 4, &adc);
    Sonar sonar(28, 29);
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
        std::cout << sonar.getDistance() << std::endl;
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
                std::cout << "ADC 1: " << adc.getAnalog(1) << "\n";
                std::cout << "ADC 2: " << adc.getAnalog(2) << "\n";
                std::cout << "ADC 3: " << adc.getAnalog(3) << "\n";
                std::cout << "ADC 4: " << adc.getAnalog(4) << "\n";
                break;
            case 'k':
                servo.rotate(-1);
                break;
            case 'l':
                servo.rotate(1);
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