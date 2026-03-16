// Copyright 2022 NNTU-CS
#include "alg.h"
#include <stdint.h>

double pown(double value, uint16_t n) {
    double ans = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        ans *= value;
    }
    return ans;
}

uint64_t fact(uint16_t n) {
    uint64_t ans = 1;
    for (uint16_t i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double ans = 0.0;
    for (uint16_t n = 0; n <= count; n++) {
        ans += calcItem(x, n);
    }
    return ans;
}

double sinn(double x, uint16_t count) {
    double ans = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        uint16_t power = 2 * n + 1;
        double t = calcItem(x, power);

        if (n % 2 == 0) {
            ans += t;
        } else {
            ans -= t;
        }
    }
    return ans;
}

double cosn(double x, uint16_t count) {
    double ans = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        uint16_t power = 2 * n;
        double t = calcItem(x, power);

        if (n % 2 == 0) {
            ans += t;
        } else {
            ans -= t;
        }
    }
    return ans;
}
