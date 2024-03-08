// Copyright 2022 NNTU-CS
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return value;
    } else {
        double result = pown(value * value, n / 2);
        return (n % 2 == 0) ? result : value * result;
    }
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        uint64_t result = 1;
        for (uint16_t i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    long double res = 0.0;
    for (uint16_t i = 0; i <= count; i++) {
        res += pown(x, i) / fact(i);
    }
    return res;
}


double sinn(double x, uint16_t count) {
    long double res = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        res += pown(-1, i) / fact(2 * i + 1) * pown(x, 2 * i + 1);
    }
    return res;
}

double cosn(double x, uint16_t count) {
    long double res = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        res += pown(-1, i) * pown(x, 2 * i) / fact(2 * i);
    }
    return res;
}
