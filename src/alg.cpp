// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double ret = value;
    if (n == 0) {
        return 1;
    }
    for (uint16_t i = 1; i < n; i++) {
        ret = ret*value;
    }
    return ret;
}

uint64_t fact(uint16_t n) {
    uint64_t ret = 1;
    for (uint16_t i = 1; i <= n; i++) {
        ret = i*ret;
    }
    return ret;
}

double calcItem(double x, uint16_t n) {
    double ret = (pown(x, n) / fact(n));
    return ret;
}

double expn(double x, uint16_t count) {
    double ret = 1;
    for (uint16_t i = 1; i <= count; i++) {
        ret += calcItem(x, i);
    }
    return ret;
}

double sinn(double x, uint16_t count) {
    double ret = 0;
    bool flag = false;
    for (uint16_t i = 1; i < 2 * count; i += 2) {
        if (flag) {
            ret -= calcItem(x, i);
            flag = false;
        } else {
            ret += calcItem(x, i);
            flag = true;
        }
    }
    return ret;
}

double cosn(double x, uint16_t count) {
    double ret = 1;
    bool flag = true;
    for (uint16_t i = 2; i < 2 * count; i += 2) {
        if (flag) {
            ret -= calcItem(x, i);
            flag = false;
        } else {
            ret += calcItem(x, i);
            flag = true;
        }
    }
    return ret;
}
