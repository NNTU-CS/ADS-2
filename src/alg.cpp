// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    double res1 = 1;
    for (uint16_t i = 0; i < n; i++) {
        res1 *= value;
    }
    return res1;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return fact(n - 1) * n;
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double expp = 0;
    for (uint16_t i = 0; i <= count; i++) {
        expp += calcItem(x, i);
    }
    return expp;
}

double sinn(double x, uint16_t count) {
    double ress1 = 0;
    for (uint16_t i = 0; i < count; i++) {
        ress1 += pown(x, 2 * i + 1) * (pown(-1, i) / fact(2 * i + 1));
    }
    return ress1;
}

double cosn(double x, uint16_t count) {
    double ress2 = 1;
    for (uint64_t i = 2; i <= count; i++) {
        ress2 += calcItem(x, (2 * i) - 2) * pown((-1.0), i - 1);
    }
    return ress2;
}
