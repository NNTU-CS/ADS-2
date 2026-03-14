// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double Ires = 1.0;
    for (int i = 0; i < n; ++i) {
        Ires *= value;
    }
    return Ires;
}

uint64_t fact(uint16_t n) {
    if (n == 0) return 1;
    uint64_t Tres = 1;
    for (uint16_t i = 1; i <= n; ++i) {
        Tres *= i;
    }
    return Tres;
}

double calcItem(double x, uint16_t n) {
    if (n == 0) return 1.0;
    double Cres = 1.0;
    for (uint16_t i = 1; i <= n; ++i) {
        Cres *= x / i;
    }
    return Cres;
}

double expn(double x, uint16_t count) {
    if (count == 0) return 0.0;
    double resi = 1.0;
    double temp = 1.0;
    for (uint16_t n = 1; n <= count; n++) {
        temp *= x / n;
        resi += temp;
    }
    return resi;
}

double sinn(double x, uint16_t count) {
    if (count == 0) return 0.0;
    double Res = 0.0;
    double temp = x;
    Res += temp;
    for (uint16_t n = 1; n < count; ++n) {
        temp *= -x * x / (2 * n * (2 * n + 1));
        Res += temp;
    }
    return Res;
}

double cosn(double x, uint16_t count) {
    if (count == 0) return 0.0;
    double rest = 1.0;
    double temp = 1.0;
    for (uint16_t n = 1; n < count; ++n) {
        temp *= -x * x / ((2 * n - 1) * (2 * n));
        rest += temp;
    }
    return rest;
}
