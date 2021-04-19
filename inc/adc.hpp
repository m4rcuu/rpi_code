#pragma once

class ADC
{
private:
    int base;
    int spi_chan;

public:
    ADC(int _base, int _spi_chan);
    const int getAnalog(const int _chanel);
};