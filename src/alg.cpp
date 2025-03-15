// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

double fact(uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        result += calcItem(x, n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        double term = pown(-1, n - 1) * pown(x, 2 * n - 1) / fact(2 * n - 1);
        result += term;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        double term = pown(-1, n - 1) * pown(x, 2 * n - 2) / fact(2 * n - 2);
        result += term;
    }
    return result;
}
