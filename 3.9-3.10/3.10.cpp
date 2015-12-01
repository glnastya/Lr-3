#include "sdt.h"
#include "convert.h"

int main ()
{
    Temperature temp{0,'C'};
    vector<Temperature> degsC, degsK, degsF;
    char sc;
    double c,k,f,s;

    while (cin)
    {
        cout <<"Enter temperature (C,F,K) = ";
        cin >> temp.value >> temp.scale;
        if (!cin)
            break;
        else
        {
            try
            {
                degsC.push_back(convert(temp,Celsius));
                degsK.push_back(convert(temp,Kelvin));
                degsF.push_back(convert(temp,Fahrenheit));
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
        cout << degsC[i].value << "\t\t";
        cout << degsK[i].value << "\t\t";
        cout << degsF[i].value << "\t\t" << "\n";
    }
}
