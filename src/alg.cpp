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
    uint64_t rezultat = 1;
    for (uint64_t i = n; i >= 1; i--) {
        rezultat *= i;
    }
    return rezultat;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    long double rez = 0.0;
    for (uint16_t i = 0; i <= count; i++) {
        rez += pown(x, i) / fact(i);
    }
    return rez;
}

double sinn(double x, uint16_t count) {
    long double rezul = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        rezul += (pown(-1, i) / fact(2 * i + 1)) * pown(x, 2 * i + 1);
    }
    return rezul;
}

double cosn(double x, uint16_t count) {
    long double res = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        res += (pown(-1, i) * pown(x, 2 * i)) / fact(2 * i);
    }
    return res;
}
