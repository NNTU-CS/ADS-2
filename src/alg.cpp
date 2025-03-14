// Copyright 2022 NNTU-CS
#include "alg.h"
#include <iostream>
#include <cstdint>
#include <cmath>

double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    double numerator = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        numerator *= x;
    }
    return numerator / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        result += term;
        term *= x / (n + 1);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double term = x;
    for (uint16_t n = 0; n < count; ++n) {
        result += term;
        term *= -x * x / ((2 * n + 2) * (2 * n + 3));
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        result += term;
        term *= -x * x / ((2 * n + 1) * (2 * n + 2));
    }
    return result;
}
