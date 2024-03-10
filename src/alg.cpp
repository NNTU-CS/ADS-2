// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    double ret = 1;
    for (uint16_t i = 0; i < n; i++) {
       ret *= value;
    }
    return ret;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    uint64_t xex = 1;
    for (uint16_t i = 1; i <= n; i++) {
        xex *= i;
    }
    return xex;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double res = 1;
    for (uint16_t i = 1; i <= count; i++) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double k = 0;
    bool flag = false;
    for (uint16_t i = 1; i < 2 * count; i += 2) {
        if (flag) {
            k -= calcItem(x, i);
        } else {
            k += calcItem(x, i);
        }
        flag = !flag;
    }
    return k;
}

double cosn(double x, uint16_t count) {
    double kk = 1;
    bool flag = true;
    for (uint16_t i = 2; i < 2 * count; i += 2) {
        if (flag) {
            kk -= calcItem(x, i);
        } else {
            kk += calcItem(x, i);
        }
        flag = !flag;
    }
    return kk;
}
