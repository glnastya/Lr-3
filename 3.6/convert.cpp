#include "sdt.h"
#include "convert.h"

double convert(double t, char from, char to)
{
    if (from == 'C' || from == 'F' || from == 'K')
    {
        if (from == 'K')
        {
            if (t < 0)
                throw invalid_argument("ErrorTempInKelvin.\n");
            else
            {
                switch (to)
                {
                case 'K':
                {
                    return(t);
                    break;
                }

                case 'C':
                    return(t - 273.15);
                    break;

                case 'F':
                    return(9/5*(t - 273.15) + 32);
                    break;
                }
            }
        }
        else if (from == 'C')
        {
            switch (to)
            {
            case 'C':
                return(t);
                break;
            case 'K':
                return(t - 273.15);
                break;
            case 'F':
                return(9/5 * t + 32);
                break;
            }
        }
        else     switch (to)
            {
            case 'F':
                return(t);
                break;
            case 'C':
                return(5/9 * (t - 32));
                break;
            case 'K':
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
