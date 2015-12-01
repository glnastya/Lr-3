#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED



#endif // CONVERT_H_INCLUDED
enum Scale //������������
{
    Kelvin,
    Celsius,
    Fahrenheit
};
struct Temperature //����������� ���������
{
    Temperature(double value,Scale scale);
    double value;
    Scale scale;
};

Temperature convert(Temperature t, Scale to); //��������������� ���������� �� ������

istream& operator>> (istream& input, Temperature& temp);
ostream& operator<< (ostream& output, const Temperature& temp);

istream& operator>> (istream& input, Scale& sc);
ostream& operator<< (ostream& output, const Scale& sc);

//���������� ����������
bool operator>(const Temperature lhs, const Temperature rhs);
Temperature operator+(const Temperature& lhs, const Temperature& rhs);
Temperature operator/(Temperature& lhs, const int del);
Temperature operator+=(Temperature& lhs, const Temperature& rhs);
Temperature operator/=(Temperature& lhs, const int del);

// ���������� ������������, ����������� � ������� ����������
Temperature maxtemp(vector<Temperature> temp);
Temperature mintemp(vector<Temperature> temp);
Temperature mean(vector<Temperature> temp);
