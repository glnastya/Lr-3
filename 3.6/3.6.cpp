#include "sdt.h"
#include "convert.h"

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
                //for (unsigned int i = 0; i < scale.size(); i++)
                //  degs[i].push_back(convert(t,sc,scale[i]));
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
