// Copyright 2022 NNTU-CS
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1.0;
    for (int i = 0; i < n; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    double res1 = 0, p = 0, f = 0;
    p = pown(x, n);
    f = fact(n);
    res1 = p / f;
    return res1;
}

double expn(double x, uint16_t count) {
    double res2 = 1;
    for (uint16_t i = 1; i <= count; i++) {
        res2 += calcItem(x, i);
    }
    return res2;
}

double sinn(double x, uint16_t count) {
    double res3 = x;
    for (uint64_t i = 2; i <= count; i++) {
        res3 += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 1);
    }
    return res3;
}

double cosn(double x, uint16_t count) {
    double res4 = 1;
    for (uint64_t i = 2; i <= count; i++) {
        res4 += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 2);
    }
    return res4;
}
