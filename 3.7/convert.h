#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED


#endif // CONVERT_H_INCLUDED

enum Scale
{
    Kelvin,
    Celsius,
    Fahrenheit
};
double convert(double t, Scale from, Scale to);
Scale change(char scale);
