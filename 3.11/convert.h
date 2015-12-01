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
ostream& operator>> (ostream& output, const Temperature& temp);

istream& operator>> (istream& input, Scale& sc);
ostream& operator>> (ostream& output, const Scale& sc);
