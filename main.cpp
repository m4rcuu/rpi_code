#include "inc/cmanipulation.hpp"
#include "inc/adc.hpp"
#include "inc/dcmotors.hpp"
#include "inc/buzzer.hpp"
#include "inc/phres.hpp"
#include "inc/servo.hpp"
#include "inc/sonar.hpp"
#include "inc/hall.hpp"
#include "inc/reflect.hpp"
#include <wiringPi.h>
#include <iostream>

int main()
{
    echoOff();
    wiringPiSetup();

    //peripheral initialization
    DcMotors motors(0, 2, 9, 8, 7, 3);
    ADC adc(100, 0);
    Servo servo(21, 15);
    Phres phres(15, 1, &adc);
    Sonar sonar(28, 29);
    Hall hall(2, &adc);
    Reflect reflect1(3, &adc);
    Reflect reflect2(4, &adc);
    Buzzer buzzer(22);

    //sound signal
    buzzer.play();
    delay(2000);
    buzzer.stop();

    //program loop
    int c = '\0';

    while (c != 27)
    {
        phres.update();

        if(sonar.getDistance()<10.0)
        {
            motors.instantBreaking();
            motors.goBack(50);
            delay(1000);
            motors.breaking();
        }

        // //printing sensor values
        // std::cout << sonar.getDistance() << std::endl;
        // std::cout << hall.getValue() << std::endl;
        // std::cout << reflect1.getValue() << std::endl;
        // std::cout << reflect2.getValue() << std::endl;

        if (kbhit())
        {
            c = getchar();

            switch (c)
            {
            case 'w':
                motors.goStraight(50);
                delay(40);
                while (kbhit())
                {
                    c = getchar();
                    if (c != 'w')
                    {
                        break;
                    }
                    delay(40);
                }
                motors.breaking();
                break;
            case 's':
                motors.goBack(50);
                delay(40);
                while (kbhit())
                {
                    c = getchar();
                    if (c != 's')
                    {
                        break;
                    }
                    delay(40);
                }
                motors.breaking();
                break;
            case 'a':
                motors.turnLeft(50);
                delay(40);
                while (kbhit())
                {
                    c = getchar();
                    if (c != 'a')
                    {
                        break;
                    }
                    delay(40);
                }
                motors.breaking();
                break;
            case 'd':
                motors.turnRight(50);
                delay(40);
                while (kbhit())
                {
                    c = getchar();
                    if (c != 'd')
                    {
                        break;
                    }
                    delay(40);
                }
                motors.breaking();
                break;
            case 'q':
                motors.rotateLeft(50);
                delay(40);
                while (kbhit())
                {
                    c = getchar();
                    if (c != 'q')
                    {
                        break;
                    }
                    delay(40);
                }
                motors.breaking();
                break;
            case 'e':
                motors.rotateRight(50);
                delay(40);
                while (kbhit())
                {
                    c = getchar();
                    if (c != 'e')
                    {
                        break;
                    }
                    delay(40);
                }
                motors.breaking();
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
            case 't':
                std::cout << sonar.getDistance() << " cm to the obstacle" << std::endl;
                break;
            case 'k':
                servo.rotate(-1);
                break;
            case 'l':
                servo.rotate(1);
                break;
            case 'c':
                system("clear");
                break;
            default:
                std::cout << "key unknown\n";
                break;
            }

            //std::cout << "got key " << c << "\n";

            c = '\0';
        }
    }
    echoOn();

    return 0;
}