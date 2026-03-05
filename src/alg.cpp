// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) return 1;
    if (n == 1) return value;
    if (n % 2) return value * pown(value, n - 1);
    else return pown(value, n / 2) * pown(value, n / 2);
}

uint64_t fact_in(uint64_t l, uint16_t r) {
    if (l > r) return 1;
    if (l == r) return l;
    return fact_in(l, (l + r) / 2 ) * fact_in(((l + r) / 2) + 1, r);
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) return 1;
    return fact_in(2, n);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double exp = 1;
    for (uint16_t u = 1; u < count+1; u++) {
        exp += calcItem(x, u);
    }
    return exp;
}

double sinn(double x, uint16_t count) {
    double sin = 0;
    uint16_t iter = 1;
    while (count) {
        if (iter % 2) sin += calcItem(x, 2*iter -1);
        else sin -= calcItem(x, 2*iter-1);
        iter++;
        count--;
    }

    return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 0;
    uint16_t iter = 1;
    while (count) {
        if (iter % 2) cos += calcItem(x, 2 * iter - 2);
        else cos -= calcItem(x, 2 * iter - 2);
        iter++;
        count--;
    }
    return cos;
}
