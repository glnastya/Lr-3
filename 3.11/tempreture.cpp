#include "sdt.h"
#include "convert.h"

Temperature::Temperature(double value, Scale scale)
{
    this->value = value;
    this->scale = scale;
}

istream& operator>> (istream& input, Temperature& temp)
{
    input >> temp.value >> temp.scale;
    return input;
}
ostream& operator<< (ostream& output, const Temperature& temp)
{
    output << temp.value << temp.scale;
    return output;
}

