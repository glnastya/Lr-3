#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED



#endif // CONVERT_H_INCLUDED
enum Scale //перечисление
{
    Kelvin,
    Celsius,
    Fahrenheit
};
struct Temperature //определение структуры
{
    Temperature(double value,char scale);
    double value;
    char scale;
};

Temperature convert(Temperature t, Scale to);


