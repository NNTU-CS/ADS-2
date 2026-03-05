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
    uint64_t re = n;
    for (uint64_t i = 2; i < n; i++) {
        re *= i;
    }
    return re;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 1.0;
    double term = 1.0;
    for (uint16_t n = 1; n <= count; n++) {
        term *= x / n;
        sum += term;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    double temp = x;
    for (uint16_t n = 1; n <= count; n++) {
        if (n > 1) {
            temp = -temp * x * x / ((2 * n - 2) * (2 * n - 1));
        }
        sum += temp;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    double temp = 1.0;
    for (uint64_t n = 1; n <= count; n++) {
        if (n > 1) {
            temp = -temp * x * x / ((2 * n - 3) * (2 * n - 2));
        }
        sum += temp;
    }
    return sum;
}
