// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        res *= value;
        }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint16_t i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double summa = 1.0;
    for (uint16_t n = 1; n < count; n++) {
        summa += calcItem(x, n);
    }
    return summa;
}

double sinn(double x, uint16_t count) {
    double summa = x;
    for (uint16_t n = 2; n < count; n += 2) {
        summa += (n % 4 == 1 ? 1 : -1) * calcItem(x, n);
    }
    return summa;
}

double cosn(double x, uint16_t count) {
    double summa = 1.0;
    for (uint16_t n = 2; n < count; n += 2) {
        summa += (n % 4 == 0 ? 1 : -1) * calcItem(x, n);
    }
    return summa;
}
