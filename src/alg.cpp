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

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
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
        sum += pown(x, n) / static_cast<double>(fact(n));
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = pown(-1, n) * pown(x, 2 * n + 1) / static_cast<double>(fact(2 * n + 1));
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = pown(-1, n) * pown(x, 2 * n) / static_cast<double>(fact(2 * n));
        sum += term;
    }
    return sum;
}
