// Copyright 2022 NNTU-CS
#include <cstdint>
double pow(double value, uint16_t n)
{
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++)
        result *= value;
    return result;
}
uint64_t fact(uint16_t n)
{
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++)
        result *= i;
    return result;
}
double calcTerm(double x, uint16_t n)
{
    return pow(x, n) / fact(n);
}
double exp(double x, uint16_t count)
{
    double sum = 0.0;
    for (uint16_t n = 0; n < count; n++)
        sum += calcTerm(x, n);
    return sum;
}
double sin(double x, uint16_t count)
{
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++)
    {
        double term = pow(x, 2*n - 1) / fact(2*n - 1);
        if ((n - 1) % 2 == 0)
            sum += term;
        else
            sum -= term;
    }
    return sum;
}
double cos(double x, uint16_t count)
{
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++)
    {
        double term = pow(x, 2*n - 2) / fact(2*n - 2);
        if ((n - 1) % 2 == 0)
            sum += term;
        else
            sum -= term;
    }
    return sum;
}
