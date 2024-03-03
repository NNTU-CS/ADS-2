// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1.0;
    for (uint16_t l = 1; l <= n; ++l) {
        res = res * value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint16_t l = 1; l <= n; ++l) {
        res = res * l;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double res = 0;
    for (uint16_t l = 0; l <= count; ++l) {
        res = res + calcItem(x, l);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0;
    int s = 1;
    for (uint16_t l = 1; l < count * 2 + 1; l += 2) {
        res = res + s * calcItem(x, l);
        s = s * -1;
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 0;
    int s = 1;
    for (uint16_t l = 0; l < count * 2; l += 2) {
        res = res + s * calcItem(x, l);
        s = s * -1;
    }
    return res;
}
