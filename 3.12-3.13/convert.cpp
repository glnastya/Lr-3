#include "sdt.h"
#include "convert.h"

Temperature convert(Temperature t, Scale to )
{
    Temperature data {0,Kelvin};
    if (t.scale== Celsius || t.scale == Kelvin || t.scale== Fahrenheit)
    {
        if (t.scale == Kelvin)
        {
            if (t.value < 0)
                throw invalid_argument("ErrorTempInKelvin.\n");
            else
            {
                switch (to)
                {
                case Kelvin:
                {
                    data.value = t.value;
                    data.scale =Kelvin;
                    break;
                }

                case Celsius:
                {
                    data.value = t.value - 273.15;
                    data.scale =Celsius;
                    break;
                }

                case Fahrenheit:
                {
                    data.value = 9/5*(t.value - 273.15) + 32;
                    data.scale =Fahrenheit;
                    break;
                }
                }
            }
        }
        else if (t.scale == Celsius)
        {
            switch (to)
            {
            case Celsius:
            {
                data.value = t.value;
                data.scale =Celsius;
                break;
            }
            case Kelvin:
            {
                data.value = t.value + 273.15;
                data.scale =Kelvin;
                break;
            }
            case Fahrenheit:
            {
                data.value =(9/5 * t.value + 32);
                data.scale =Fahrenheit;
                break;
            }
            }
        }
        else     switch (to)
            {
            case Fahrenheit:
            {
                data.value = t.value;
                data.scale =Fahrenheit;
                break;
            }
            case Celsius:
            {
                data.value = 5/9 * (t.value - 32);
                data.scale =Celsius;
                break;
            }
            case Kelvin:
            {
                data.value = 5/9 * (t.value - 32) + 273.15;
                data.scale =Kelvin;
                break;
            }
            }
    }
    else
    {
        throw logic_error("Unknown scale!");
    }
    return data;
}
istream& operator>> (istream& input, Scale& sc)
{
    char s;
    input>> s;
    switch (s)
    {
    case 'C':
        sc = Celsius;
        break;
    case 'K':
        sc = Kelvin;
        break;
    case 'F':
        sc = Fahrenheit;
        break;
    default :
        input.setstate(ios_base::failbit);
    }
    return input;
}
ostream& operator<< (ostream& output, const Scale& sc)
{
    switch (sc)
    {
    case Celsius:
        output << 'C';
        break;
    case Kelvin:
        output << 'K';
        break;
    case Fahrenheit:
        output << 'F';
    }
    return output;
}


