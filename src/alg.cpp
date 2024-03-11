// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double k = value;
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i < n; i++) {
        k *= value;
    }
    return k;
}

uint64_t fact(uint16_t n) {
    uint64_t k = 1;
    for (int i = 1; i <= n; i++) {
        k *= i;
    }
    return k;
}

double calcItem(double x, uint16_t n) {
    double k = 0;
    k = (pown(x, n)) / (fact(n));
    return k;
}

double expn(double x, uint16_t count) {
    double p = 1;
    for (int i = 1; i <= count; i++) {
        p += calcItem(x, i);
    }
    return p;
}

double sinn(double x, uint16_t count) {
    double n = 0;
    for (int i = 1; i <= count; i++) {
        n += (pown(-1, i - 1)) * (calcItem(x, 2 * i - 1));
    }
    return n;
}

double cosn(double x, uint16_t count) {
    double n = 0;
    for (int i = 1; i <= count; i++) {
        n += (pown(-1, i - 1)) * (calcItem(x, 2 * i - 2));
    }
    return n;
}
