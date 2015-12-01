#include "sdt.h"
#include "convert.h"

Temperature::Temperature(double value, Scale scale)
{
    this->value = value;
    this->scale = scale;
}

istream& operator>> (istream& input, Temperature& temp)
{
    input >> temp.value >> temp.scale;
    return input;
}
ostream& operator<<(ostream& output, const Temperature& temp)
{
    output<<temp.value <<temp.scale;
    return output;
}

//перегрузка операторов
bool operator>(const Temperature& lhs, const Temperature& rhs)
{
    Temperature T = convert(rhs, lhs.scale);
    return lhs.value > T.value;
}

Temperature operator+(const Temperature& lhs, const Temperature& rhs)
{
    Temperature T = convert(rhs, lhs.scale);
    return  {lhs.value + T.value,
             lhs.scale};
}

Temperature operator/(Temperature& lhs, const int del)
{
    return  {lhs.value / del,
             lhs.scale};
}

Temperature operator+=(Temperature& lhs, const Temperature& rhs)
{
    Temperature T = convert(rhs, lhs.scale);
    lhs.value += T.value;
    return lhs;
}


Temperature operator/=(Temperature& lhs, const int del)
{
    lhs.value /= del;
    return lhs;
}
//функции определения максимальной, минимальной и средней температуры
Temperature maxtemp(vector<Temperature> temp)
{
    Temperature maxt = temp[0];
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i].value > maxt.value)
            maxt = temp[i];
    }
    return maxt;
}

Temperature mintemp(vector<Temperature> temp)
{
    Temperature mintemp  {0, Celsius};
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].value < mintemp.value)
            mintemp = temp[i];
    }
    return mintemp;
}

Temperature mean(vector<Temperature> temp)
{
    Temperature mean  {0, Celsius};
    for (int i=0; i < temp.size(); i++)
    {
        mean += temp[i];
    }
    mean /= temp.size();
    return mean;
}
