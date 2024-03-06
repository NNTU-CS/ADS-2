// Copyright 2022 NNTU-CS
#include "alg.h"

double pown(double value, uint16_t n) {
    double r = value;
    for (uint64_t i = 2; i <= n; i++) {
        r *= value;
    }
    return r;
}

uint64_t fact(uint16_t n) {
    uint64_t r = 1;
    for (uint64_t i = 1; i <= n; i++) {
        r *= i;
    }
    return r;
}

double calcItem(double x, uint16_t n) {
    double chisl = x;
    for (uint64_t i = 2; i <= n; i++) {
        chisl *= x;
    }
    double znam = 1;
    for (double i = 1; i <= n; i++) {
        znam *= i;
    }
    return chisl / znam;
}

double expn(double x, uint16_t count) {
    double sum = 1;
    for (uint64_t i = 1; i <= count; i++) {
        sum += pown(x, i) / fact(i);
    }
    return sum;
}

double sinn(double x, uint16_t n) {
    double sum = 0;
    bool flag = false;
    for (uint16_t i = 1; i < 2*n; i += 2) {
        if (flag) {
            sum -= calcItem(x, i);
            flag = false;
        } else {
            sum += calcItem(x, i);
            flag = true;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1;
    bool flag = true;
    for (uint16_t i = 2; i < 2*count; i += 2) {
        if (flag) {
            sum -= calcItem(x, i);
            flag = false;
        } else {
            sum += calcItem(x, i);
            flag = true;
        }
    }
    return sum;
}
