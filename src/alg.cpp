// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>

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
    return pown(x, n) / (double)fact(n);
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
    for (uint16_t n = 1; n <= count; n += 2) {
        double term = calcItem(x, n);
        if (((n - 1) / 2) % 2 == 1) {
            term = -term;
        }
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n <= count; n += 2) {
        double term = calcItem(x, n);
        // Знак чередуется: (-1)^(n/2)
        if ((n / 2) % 2 == 1) {
            term = -term;
        }
        sum += term;
    }
    return sum;
}
