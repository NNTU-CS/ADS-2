// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double p = value;
    for (uint64_t i = 2; i <= n; i++) {
        p *= value;
    }
    return p;
}

uint64_t fact(uint16_t n) {
    uint64_t p = 1;
    for (uint64_t i = 1; i <= n; i++) {
        p *= i;
    }
    return p;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double e = 0;
    for (uint64_t i = 0; i <= count ; i++) {
        e += calcItem(x, i);
    }
    return e;
}

double sinn(double x, uint16_t n) {
    double sum = 0;
    bool flag = false;
    for (uint16_t i = 1; i < 2 * n; i += 2) {
        if (flag) {
            sum -= calcItem(x, i);
            flag = false;
        } else {
            sum += calcItem(x, i);
            flag = true;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1;
    bool flag = true;
    for (uint16_t i = 2; i < 2 * count; i += 2) {
        if (flag) {
            sum -= calcItem(x, i);
            flag = false;
        } else {
            sum += calcItem(x, i);
            flag = true;
        }
    }
    return sum;
}
