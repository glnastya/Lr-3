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
    Temperature(double value,char scale);
    double value;
    char scale;
};

Temperature convert(Temperature t, Scale to);


