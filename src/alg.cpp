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
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double sum = 1.0;
    for (uint16_t i = 1; i < count; ++i) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        sum += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i + 1);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1.0;
    for (uint16_t i = 1; i < count; ++i) {
        sum += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i);
    }
    return sum;
}
