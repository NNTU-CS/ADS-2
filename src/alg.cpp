// Copyright 2025 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= value;
        }
        value *= value;
        n /= 2;
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

double calcItemExp(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double calcItemSin(double x, uint16_t n) {
    return pown(-1, n) * pown(x, 2 * n + 1) / fact(2 * n + 1);
}

double calcItemCos(double x, uint16_t n) {
    return pown(-1, n) * pown(x, 2 * n) / fact(2 * n);
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItemExp(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItemSin(x, n);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItemCos(x, n);
    }
    return sum;
}
