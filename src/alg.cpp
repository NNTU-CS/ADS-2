// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pow(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0) return 1;
    uint64_t result = 1;
    for (uint16_t i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pow(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        uint16_t n = 2 * i + 1;
        double item = calcItem(x, n);
        if (i % 2 == 1) item = -item;
        result += item;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        uint16_t n = 2 * i;
        double item = calcItem(x, n);
        if (i % 2 == 1) item = -item;
        result += item;
    }
    return result;
}
