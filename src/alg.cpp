// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1.0;
    while (n > 0) {
        res *= n;
        --n;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double res = 0;
    for (uint16_t i = 0; i <= count; ++i) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0;
    for (uint16_t i = 1; i <=count; ++i) {
        res += ((i % 2) ? 1 : -1) * calcItem(x, 2 * i - 1);
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 0;
    for (uint16_t i = 1; i <= count; ++i) {
        res += ((i % 2) ? 1 : -1) * calcItem(x, 2 * i - 2);
    }
    return res;
}
