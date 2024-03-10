// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double rez = 1.0;
    for (uint64_t i = 0; i < n; i++) {
        rez *= value;
    }
    return rez;
}

uint64_t fact(uint16_t n) {
    uint64_t rez = 1;
    for (uint64_t i = 1; i <= n; i++) {
        rez *= i;
    }
    return rez;
}

double calcItem(double x, uint16_t n) {
    double rez = pown(x, n) / fact(n);
    return rez;
}

double expn(double x, uint16_t count) {
    double rez = 1;
    for (uint16_t i = 1; i <= count; i++) {
        rez += calcItem(x, i);
    }
    return rez;
}

double sinn(double x, uint16_t count) {
    double rez = x;
    for (uint16_t i = 2; i <= count; i++) {
        rez += pown((-1.0), i - 1) * calcItem(x, (i * 2) - 1);
    }
    return rez;
}

double cosn(double x, uint16_t count) {
    double rez = 1.0;
    for (uint16_t i = 2; i <= count; i++) {
        rez += pown((-1.0), i - 1) * calcItem(x, (i * 2) - 2);
    }
    return rez;
}
