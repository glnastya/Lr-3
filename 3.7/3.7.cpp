#include "sdt.h"
#include "convert.h"

int main ()
{
    vector<double>  degsC, degsK, degsF;
    char sc;
    double t,c,k,f,s;

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
                Scale s = change(sc);
                degsC.push_back(convert(t,s,Celsius));
                degsK.push_back(convert(t,s,Kelvin));
                degsF.push_back(convert(t,s,Fahrenheit));
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
