#include "sdt.h"
#include "convert.h"

double convert(double t, Scale from, Scale to)
{
    if (from == Celsius || from == Kelvin || from == Fahrenheit)
    {
        if (from == Kelvin)
        {
            if (t < 0)
                throw invalid_argument("ErrorTempInKelvin.\n");
            else
            {
                switch (to)
                {
                case Kelvin:
                {
                    return(t);
                    break;
                }

                case Celsius:
                    return(t - 273.15);
                    break;

                case Fahrenheit:
                    return(9/5*(t - 273.15) + 32);
                    break;
                }
            }
        }
        else if (from == Celsius)
        {
            switch (to)
            {
            case Celsius:
                return(t);
                break;
            case Kelvin:
                return(t - 273.15);
                break;
            case Fahrenheit:
                return(9/5 * t + 32);
                break;
            }
        }
        else     switch (to)
            {
            case Fahrenheit:
                return(t);
                break;
            case Celsius:
                return(5/9 * (t - 32));
                break;
            case Kelvin:
                return(5/9 * (t - 32) + 273.15);
                break;
            }
    }
    else
    {
        throw logic_error("Unknown scale!");
    }
    throw exception();
}
Scale change(char sc)
{
    switch (sc)
    {
    case 'C':
        return Celsius;
        break;
    case 'F':
        return Fahrenheit;
        break;
    case 'K':
        return Kelvin;
        break;
    default:
        throw invalid_argument("Unknown scale.\n");
    }
}
