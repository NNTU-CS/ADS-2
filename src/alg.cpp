// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0)
        return 1.0;
    else if (n % 2 == 0) {
        double half_power = pown(value, n / 2);
        return half_power * half_power;
    }
    else {
        return value * pown(value, n - 1);
    }
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return static_cast<uint64_t>(n) * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    double result = 1.0; 
    for (uint16_t i = 1; i <= n; ++i) {
        result *= x / i; 
    }
    return result;
}

double expn(double x, uint16_t count) {
    double result = 1.0; 
    double factorial = 1.0; 
    double power_x = 1.0; 

    for (uint16_t i = 1; i < count; ++i) {
        factorial *= i; 
        power_x *= x; 
        result += power_x / factorial;
    }

    return result;
}
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double term = x;
    double sign = 1.0;

    for (uint16_t n = 1; n <= count; ++n) {
        result += sign * term;
        sign *= -1.0;
        term *= (x * x) / ((2 * n) * (2 * n + 1));
    }

    return result;
}

double cosn(double x, uint16_t count) {
    double result = 1.0;
    double term = 1.0;
    int sign = -1;
    for (uint16_t i = 1; i < count; ++i) {
        term *= x * x / ((2 * i) * (2 * i - 1)); 
        term *= sign; 
        result += term; 
        sign *= -1; 
    }
    return result;
}
