// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include <iostream>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    if (n == 0) {
        return 1.0;
    }
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double factorial(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    double result = 1.0;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pow(x, n) / factorial(n);
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += pow(x, n) / factorial(n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        sum += term;
    }
    return sum;
}
