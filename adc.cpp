#include "inc/adc.hpp"
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>

ADC::ADC(int _base, int _spi_chan) : base(_base),
                                     spi_chan(_spi_chan)
{
    mcp3004Setup(base, spi_chan);
}

const int ADC::getAnalog(const int _chanel)
{
    return analogRead(base + _chanel);
}