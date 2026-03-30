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
    if (n == 0) return 1.0;
    double numerator = pown(x, n);
    uint64_t denominator = fact(n);
    return numerator / static_cast<double>(denominator);
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
    for (uint16_t n = 0; n < count; ++n) {
        uint16_t power = 2 * n + 1;
        double numerator = pown(x, power);
        uint64_t denominator = fact(power);
        double item = numerator / static_cast<double>(denominator);
        if (n % 2 == 1) {
            item = -item;
        }
        sum += item;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        uint16_t power = 2 * n;
        double numerator = pown(x, power);
        uint64_t denominator = fact(power);
        double item = numerator / static_cast<double>(denominator);
        if (n % 2 == 1) {
            item = -item;
        }
        sum += item;
    }
    return sum;
}
