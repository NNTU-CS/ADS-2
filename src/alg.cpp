// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double ans = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        ans *= value;
    }
    return ans;
}

uint64_t fact(uint16_t n) {
    if (n <= 1) return 1;
    uint64_t ans = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double suma = 1.0;
    for (uint16_t n = 1; n <= count; ++n) {
        suma += calcItem(x, n);
    }
    return suma;
}

double sinn(double x, uint16_t count) {
    double suma = 0.0;
    int zn = 1;

    for (uint16_t n = 1; n <= count; ++n) {
        uint16_t power = 2 * n - 1; 
        suma += zn * calcItem(x, power);
        zn = -zn;
    }
    return suma;
}


double cosn(double x, uint16_t count) {
    double suma = 0.0;
    int zn = 1;

    for (uint16_t n = 1; n <= count; ++n) {
        uint16_t power = 2 * n - 2;
        if (power == 0) {
            suma += zn * 1.0;
        }
        else {
            suma += zn * calcItem(x, power);
        }
        zn = -zn;
    }
    return suma;
}
