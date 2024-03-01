// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return value;
    } else if (n % 2 == 0) {
        return pown(value * value, n / 2);
    } else {
        return value * pown(value * value, n / 2);
    }
}

uint64_t fact(uint16_t n) {
    uint64_t r = 1;
    while (n > 0) {
        r *= n;
        n--;
    }
return r;
}

double calcItem(double x, uint16_t n) {
    double d;
    d = pown(x, n) / fact(n);
return d;
}

double expn(double x, uint16_t count) {
    double d = 0;
    for (int i = 0; i <= count; i++) {
        d += pown(x, i) / fact(i);
    }
return d;
}

double sinn(double x, uint16_t count) {
    double sin = 0;
    for (int i = 1; i <= count; i++) {
        if (i % 2 == 0) {
            sin -= pown(x, 2 * i - 1) / fact(2 * i - 1);
        } else {
            sin += pown(x, 2 * i - 1) / fact(2 * i - 1);
        }
    }
return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 0;
    for (int i = 1; i <= count; i++) {
        if (i % 2 == 0) {
            cos -= pown(x, 2 * i - 2) / fact(2 * i - 2);
        } else {
            cos += pown(x, 2 * i - 2) / fact(2 * i - 2);
        }
    }
return cos;
}
