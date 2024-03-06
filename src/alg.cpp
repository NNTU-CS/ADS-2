// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double numInPow = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        numInPow *= value;
    }
    return numInPow;
}

uint64_t fact(uint16_t n) {
    if (n <= 1) {
        return 1;
    } 
    else {
        uint64_t resFact = 1;
        for (uint64_t i = 2; i <= n; i++) {
            resFact *= i;
        }
    return resFact;
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double resExpn = 0.0;
    for (uint16_t i = 0; i <= count; i++) {
        resExpn += calcItem(x, i);
    }
    return resExpn;
}

double sinn(double x, uint16_t count) {
    double reSin = 0.0;
    for (uint16_t i = 1; i <= count; i++) {
        reSin += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
    }
    return reSin;
}

double cosn(double x, uint16_t count) {
    double resCos = 0.0;
    for (uint16_t i = 1; i <= count; i++) {
        resCos += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
    }
    return resCos;
}
