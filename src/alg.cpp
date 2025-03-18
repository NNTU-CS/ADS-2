// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double res = 1.0;
    double base = value;
    while (n > 0) {
        if (n % 2 == 1) {
            res *= base;
        }
        base *= base;
        n /= 2;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint16_t i = 2; i <= n; ++i) { 
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    double numerator = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        numerator *= x;
    }

    uint64_t denominator = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        denominator *= i;
    }
    return numerator / static_cast<double>(denominator);
}


double expn(double x, uint16_t count) {
    double res = 1.0;
    double term = 1.0;
    for (uint16_t i = 1; i <= count; ++i) {
        term *= x / static_cast<double>(i);
        res += term;
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0.0;
    double term = x;
    for (uint16_t i = 1; i <= count; ++i) {
        res += term;
        term *= -x * x / static_cast<double>((2 * i) * (2 * i + 1));
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1.0;
    double term = 1.0;
    double x_squared = -x * x;

    for (uint16_t i = 1; i <= count; ++i) {
        term *= x_squared / static_cast<double>((2 * i - 1) * (2 * i));
        res += term;
    }
    return res;
}
