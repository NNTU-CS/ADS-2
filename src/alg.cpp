// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    long double res = 1.0L;
    while (n > 0) {
        if (n % 2 == 1) {
            res *= value;
        }
        value *= value;
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
    long double res = 1.0L;
    for (uint16_t i = 0; i < n; ++i) {
        res *= x;
    }
    for (uint16_t i = 1; i <= n; ++i) {
        res /= i;
    }
    return res;
}

double expn(double x, uint16_t count) {
    double res = 1.0;
    double c = 1.0;
    for (uint16_t n = 1; n < count; ++n) {
        c *= x / n;
        res += c;
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0.0;
    double c = x;
    int sign = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        res += sign * c;
        c *= x * x / ((2 * i) * (2 * i + 1));
        sign = -sign;
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 0.0;
    double c = 1.0;
    int sign = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        res += sign * c;
        c *= x * x / ((2 * i - 1) * (2 * i));
        sign = -sign;
    }
    return res;
}
