// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double res = 1;
    for (uint16_t i = 1; i <= n; ++i) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double res = x;
    for (uint16_t i = 1; i < count; i++) {
        res += calcItem(x, 2 * i + 1)* pown(-1, i % 2);
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    for (uint16_t i = 1; i < count; i++) {
        res += calcItem(x, 2 * i) * pown(-1, i % 2);
    }
    return res;
}
