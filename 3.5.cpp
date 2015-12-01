
#include "sdt.h"

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
int main ()
{
    vector<double>  degsC, degsK, degsF;
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
            try
            {
                degsC.push_back(convert(t,sc,'C'));
                degsK.push_back(convert(t,sc,'K'));
                degsF.push_back(convert(t,sc,'F'));
            }
            catch (const invalid_argument& e)
            {
                cerr << e.what() << "\n";
            }
            catch (const logic_error& le)
            {
                cerr << le.what() << "\n";
            }
            catch (...)
            {
                cerr << "Unknown error!\n";
            }
        }
    }
    cout <<"\n";
    cout <<"C \t\t" <<"K \t\t" <<"F \t\t \n";
    for ( int i = 0; i < degsC.size(); ++i)
    {
        cout << degsC[i] << "\t\t";
        cout << degsK[i] << "\t\t";
        cout << degsF[i] << "\t\t" << "\n";
    }
}






