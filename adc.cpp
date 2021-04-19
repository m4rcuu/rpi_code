#include "inc/adc.hpp"
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>

ADC::ADC(const int _base, const int _spi_chan) : base(_base),
                                     spi_chan(_spi_chan)
{
    mcp3004Setup(base, spi_chan);
}

const int ADC::getAnalog(const int _chanel)
{
    return analogRead(base + _chanel - 1);
}