// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double r = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        r *= value;
    }
    return r;
}
uint64_t fact(uint16_t n) {
    uint64_t r = 1;
    for (uint16_t i = 1; i <= n; i++) {
        r *= i;
    }
    return r;
}
double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}
double expn(double x, uint16_t count) {
    double s = 0.0;
    for (uint16_t i = 0; i <= count; i++) {
        s += calcItem(x, i);
    }
    return s;
}
double sinn(double x, uint16_t count) {
    double s = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        double a = (pown(x, 2*i + 1) / fact(2*i + 1)) * pown(-1, i);
        s += a;
    }
    return s;
}
double cosn(double x, uint16_t count) {
    double s = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        double a = (pown(x, 2*i) / fact(2*i)) * pown(-1, i);
        s += a;
    }
    return s;
}
