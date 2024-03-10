// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1.0;
    for (uint64_t i = 0; i < n; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint64_t i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    double res = pown(x, n) / fact(n);
    return res;
}

double expn(double x, uint16_t count) {
    double res = 1;
    for (uint16_t i = 1; i <= count; i++) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = x;
    for (uint16_t i = 2; i <= count; i++) {
        res += pown((-1.0), i - 1) * calcItem(x, (i * 2) - 1);
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1.0;
    for (uint16_t i = 2; i <= count; i++) {
        res += pown((-1.0), i - 1) * calcItem(x, (i * 2) - 2);
    }
    return res;
}
