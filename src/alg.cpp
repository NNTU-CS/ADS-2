// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    uint16_t i;
    double count = 1;
    for (i = 0; i < n; i++) {
        count *= value;
    }
    return count;
}

uint64_t fact(uint16_t n) {
    uint64_t i, count = 1;
    for (i = 1; i <= n; i++) {
        count *= i;
    }
    return count;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double e = 1;
    uint16_t n;
    for (n = 1; n <= count; n++) {
    e += calcItem(x, n);
    }
    return e;
}

double sinn(double x, uint16_t count) {
    double s = 0;
    uint16_t n;
    for (n = 1; n <= count; n++) {
        s += pown(-1, n - 1) * calcItem(x, (2 * n) - 1);
    }
    return s;
}

double cosn(double x, uint16_t count) {
    double c = 1;
    uint16_t n;
    for (n = 2; n <= count; n++) {
        c += pown(-1, n - 1) * calcItem(x, (2 * n) - 2);
    }
    return c;
}
