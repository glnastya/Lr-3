#include "sdt.h"
#include "convert.h"

Temperature::Temperature(double value, char scale)
{
    this->value = value;
    this->scale = scale;
}

