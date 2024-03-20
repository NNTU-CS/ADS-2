// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double r = 1;
    for (uint16_t i = 0; i < n; i++) {
        r *= value;
    }
    return r;
}

uint64_t fact(uint16_t n) {
    uint64_t r = 1;
    for (uint16_t i = 2; i <= n; i++) {
        r *= i;
    }
    return r;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double r = 0;
    for (uint16_t i = 0; i <= count; i++) {
        r += calcItem(x, i);
    }
    return r;
}

double sinn(double x, uint16_t count) {
    double r = 0;
    for (uint16_t n = 1; n <= count; n++) {
        r += pown(-1, n - 1) * calcItem(x, 2 * n - 1);
    }
    return r;
}

double cosn(double x, uint16_t count) {
    double r = 0;
    for (uint16_t n = 1; n <= count; n++) {
        r += pown(-1, n - 1) * calcItem(x, 2 * n - 2);
    }
    return r;
}
