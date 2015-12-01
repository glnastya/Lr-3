#include "sdt.h"
#include "convert.h"

int main ()
{
    Temperature input {0,Kelvin};
    vector<Temperature> degsC, degsK, degsF;
    while (cin)
    {
        cout <<"Enter temperature (C,F,K) = ";
        if (!(cin>> input))
            break;
        else
        {
            try
            {
                degsC.push_back(convert(input,Celsius));
                degsK.push_back(convert(input,Kelvin));
                degsF.push_back(convert(input,Fahrenheit));
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
    ofstream output("lab3.txt", ios_base::trunc);
    cout <<"\n";
    output<<"C \t\t" <<"K \t\t" <<"F \t\t \n";
    cout <<"C \t\t" <<"K \t\t" <<"F \t\t \n";
    for ( int i = 0; i < degsC.size(); ++i)
    {
        cout << degsC[i].value << "\t\t";
        cout << degsK[i].value << "\t\t";
        cout << degsF[i].value << "\t\t" << endl;
        output << degsC[i].value << "\t\t";
        output << degsK[i].value << "\t\t";
        output << degsF[i].value << "\t\t\n" ;
    }
    cout<<endl;
    output <<"Max temperature = " << maxtemp(degsC) <<endl;
    output <<"Min temperature = " << mintemp(degsC) << endl;
    output <<"Mean temperature = " << mean(degsC) << endl;
    cout <<"Max temperature = " << maxtemp(degsC) << endl;
    cout <<"Min temperature = " << mintemp(degsC) << endl;
    cout <<"Mean temperature = " << mean(degsC) << endl;
}

