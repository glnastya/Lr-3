#include "sdt.h"

enum Error {not_error, error_scale, error_tempreture_K };

Error convert(double t, char from, char to, double& result)
{
    if (from == 'C' || from == 'F' || from == 'K')
    {
        if (from == 'K')
        {
            if (t < 0)
                return error_tempreture_K;
            else
            {
                switch (to)
                {
                case 'K':
                {
                    result = t;
                    return not_error;
                    break;
                }

                case 'C':
                    result = t - 273.15;
                    return not_error;
                    break;

                case 'F':
                    result = 9/5*(t - 273.15) + 32;
                    return not_error;
                    break;
                }
            }
        }
        else if (from == 'C')
        {
            switch (to)
            {
            case 'C':
                result = t;
                return not_error;
                break;
            case 'K':
                result = t - 273.15;
                return not_error;
                break;
            case 'F':
                result = 9/5 * t + 32;
                return not_error;
                break;
            }
        }
        else     switch (to)
            {
            case 'F':
                result = t;
                return not_error;
                break;
            case 'C':
                result =  5/9 * (t - 32);
                return not_error;
                break;
            case 'K':
                result =  5/9 * (t - 32) + 273.15;
                return not_error;
                break;
            }
    }
    else
        return error_scale;
}
int main ()
{
    vector<double> degsC, degsK, degsF;
    char sc;
    double t,c,k,f;
    while (cin)
    {
        cout <<"Enter temperature (C,F,K) = ";
        cin >> t >> sc;
        if (!cin)
            break;
        else
        {
            switch (convert(t, sc, 'K', k))
            {
            case error_scale:
                cerr<< "unknown scale.\n";
                break;
            case error_tempreture_K:
                cerr<<"ErrorTempInKelvin. \n";
                break;
            case not_error :
                degsK.push_back(k);
                convert(t,sc,'C',c);
                degsC.push_back(c);
                convert(t,sc,'F',f);
                degsF.push_back(f);
                break;
            default:
                cerr<< "Unknown error!";
            }
        }
    }
    cout <<"\n";
    cout <<"C \t\t" <<"K \t\t" <<"F \t\t \n";
    for (int i = 0; i < degsK.size(); ++i)
    {
        cout << degsC[i] << "\t\t";
        cout << degsK[i] << "\t\t";
        cout << degsF[i] << "\t\t" << "\n";
    }
}






