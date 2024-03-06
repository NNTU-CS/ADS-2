// Copyright 2022 NNTU-CS
#include <cstdint>
#include "cmath"
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1;
    for (uint64_t j = 0; j < n; j++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint64_t i = 1; i <= n; i++)
        res *= i;
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint64_t n = 0; n <= count; n++) {
        result += pown(x, n) / fact(n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double r = 0.0;
    for (uint64_t n = 1; n <= count; n++) {
        ++r;
        result += pown(-1, r - 1) * (pown(x, 2 * n - 1) / fact(2 * n - 1));
    }
    return result;
}


double cosn(double x, uint16_t count) {
    double result = 0.0;
    double r = 0.0;
    for (uint64_t n = 1; n <= count; n++) {
        ++r;
        result += pown(-1, r - 1) * (pown(x, 2 * n - 2) / fact(2 * n - 2));
    }
    return result;
}
