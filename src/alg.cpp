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
    double result = 1.0;
    for (uint16_t i = 1; i <= n; ++i) {
        result *= x / static_cast<double>(i);
    }
    return result;
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    double item = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        result += item;
        item *= x / static_cast<double>(n + 1);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double item = x;
    for (uint16_t n = 1; n <= count; ++n) {
        if (n % 2 == 1) {
            result += item;
        } else {
            result -= item;
        }
        item *= x * x / static_cast<double>((2*n) * (2*n + 1));
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    double item = 1.0;
    for (uint16_t n = 1; n <= count; ++n) {
        if (n % 2 == 1) {
            result += item;
        } else {
            result -= item;
        }
        item *= x * x / static_cast<double>((2*n-1) * (2*n));
    }
    return result;
}
