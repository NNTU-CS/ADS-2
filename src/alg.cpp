// Copyright 2022 NNTU-CS
#include <cstdint>
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
    if (factorialCache.find(n) != factorialCache.end()) {
        return factorialCache[n];
    }
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    factorialCache[n] = result;
    return result;
}

double calcItem(double x, uint16_t n) {
    static bool isExp = true; // Флаг для определения типа ряда
    if (isExp) {
        return pown(x, n) / static_cast<double>(fact(n));
    } else {
        return pown(-1, n) * pown(x, 2 * n + (
            isExp ? 0 : 1)) / static_cast<double>(fact(
                2 * n + (isExp ? 0 : 1)));
    }
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}
