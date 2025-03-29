// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1;
    for (uint16_t i = 0; i < n; i++) {
        res*=value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint16_t i = n; i > 0; i--) {
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    double Xn = pown(x, n);
    uint64_t N = fact(n);
    double res = Xn / N;
    return res;
}

double expn(double x, uint16_t count) {
    double e = 1.0;
    for (uint16_t i = 1; i <= count; i++) {
        e += calcItem(x, i);
    }
    return e;
}

double sinn(double x, uint16_t count) {
    double sinx = 0;
    for (uint16_t n = 1; n <= count; n++) {
        sinx+= pown(-1, n-1) * calcItem(x, 2*n-1);
    }
    return sinx;
}

double cosn(double x, uint16_t count) {
    double cosx = 0;
    for (uint16_t n = 1; n <= count; n++) {
        cosx+= pown(-1, n-1) * calcItem(x, 2*n-2);
    }
    return cosx;
}
