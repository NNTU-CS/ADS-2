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

double calcItem(double x, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    if (n % 2 == 1) {
        return pown(x, n) / fact(n);
    } else {
        return pown(-1, n / 2) * pown(x, n) / fact(n);
    }
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n <= count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        sum += pown(-1, n - 1) * pown(x, 2 * n - 1) / fact(2 * n - 1);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        sum += pown(-1, n - 1) * pown(x, 2 * (n - 1)) / fact(2 * (n - 1));
    }
    return sum;
}
