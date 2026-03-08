// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    double factorial = 1.0;
    for (uint16_t i = 2; i <= n; ++i) {
        factorial *= i;
    }
    return pown(x, n) / factorial;
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            term = 1.0;
        } else {
            term *= x / n;
        }
        result += term;
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double term = x;
    for (uint16_t n = 1; n <= count; ++n) {
        uint16_t power = 2 * n - 1;
        if (n == 1) {
            term = x;
        } else {
            term *= -x * x / ((2 * n - 2) * (2 * n - 1));
        }
        result += term;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    double term = 1.0;
    for (uint16_t n = 1; n <= count; ++n) {
        if (n == 1) {
            term = 1.0;
        } else {
            term *= -x * x / ((2 * n - 3) * (2 * n - 2));
        }
        result += term;
    }
    return result;
}
