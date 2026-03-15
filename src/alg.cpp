// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double res = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint16_t i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 1.0;
    double term = 1.0;

    for (uint16_t n = 1; n <= count; n++) {
        term *= x / static_cast<double>(n);
        sum += term;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        uint16_t k = 2 * n + 1;
        double term = pown(x, k) / static_cast<double>(fact(k));
        if (n % 2 == 1) {
            term = -term;
        }
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        uint16_t k = 2 * n;
        double term = pown(x, k) / static_cast<double>(fact(k));
        if (n % 2 == 1) {
            term = -term;
        }
        sum += term;
    }
    return sum;
}
