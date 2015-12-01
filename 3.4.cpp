#include "sdt.h"


enum Error {not_error, error_scale, error_tempreture_K };

Error last_error = not_error;
Error get_last_error()
{
    return last_error;
}
double convert(double t, char from, char to)
{
    if (from == 'C' || from == 'F' || from == 'K')
    {
        if (from == 'K')
        {
            if (t < 0)
                last_error = error_tempreture_K;
            else
            {
                switch (to)
                {
                case 'K':
                {
                    return(t);
                    last_error = not_error;
                    break;
                }

                case 'C':
                    return(t - 273.15);
                    last_error = not_error;
                    break;

                case 'F':
                    return(9/5*(t - 273.15) + 32);
                    last_error = not_error;
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
                last_error = not_error;
                break;
            case 'K':
                return(t - 273.15);
                last_error = not_error;
                break;
            case 'F':
                return(9/5 * t + 32);
                last_error = not_error;
                break;
            }
        }
        else     switch (to)
            {
            case 'F':
                return(t);
                last_error = not_error;
                break;
            case 'C':
                return(5/9 * (t - 32));
                last_error = not_error;
                break;
            case 'K':
                return(5/9 * (t - 32) + 273.15);
                last_error = not_error;
                break;
            }
    }
    else
        last_error = error_scale;
}

int main ()
{
    vector<double> degsC, degsK, degsF;
    char sc;
    double t,c,k,f,x;

    while (cin)
    {
        cout <<"Enter temperature (C,F,K) = ";
        cin >> t >> sc;
        if (!cin)
            break;
        else
        {
            c = convert(t, sc, 'C');
            k = convert(t, sc, 'K');
            f = convert(t, sc, 'F');

            switch (get_last_error())
            {
            case error_scale:
                cerr<< "unknown scale.\n";
                break;
            case error_tempreture_K:
                cerr<<"ErrorTempInKelvin. \n";
                break;
            case not_error:
                    degsC.push_back(c);
                    degsK.push_back(k);
                    degsF.push_back(f);
            }
        }
        last_error = not_error;
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






