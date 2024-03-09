// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>

double pown(double value, uint16_t n) {
    if (n == 0)
        return 1;
    else
        return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double i = 1;
    for (uint16_t n = 1; n <= count; n++) {
        i += calcItem(x, n);
    }
    return i;
}

double sinn(double x, uint16_t count) {
    double j = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        j += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n + 1);
    }
    return j;
}

double cosn(double x, uint16_t count) {
    double b = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        b += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n);
    }
    return b;
}
