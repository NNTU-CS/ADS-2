// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double iCount = 1;
    for (uint16_t i = 1; i <= n ; i++) {
        iCount *= value;
    }
    return iCount;
}

uint64_t fact(uint16_t n) {
    uint64_t iCount1 = 1;
    for (uint16_t i = 1; i <= n; i++) {
        iCount1 *= i;
    }
    return iCount1;
}

double calcItem(double x, uint16_t n) {
    return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
    double exe = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        exe += calcItem(x, i);
    }
    return exe;
}

double sinn(double x, uint16_t count) {
    int chet = 1;
    double iCount3 = 0;
    for (uint16_t i = 1; i <= count*2; i += 2) {
        iCount3 += (chet % 2 == 0 ? -1 : 1) * (calcItem(x, i));
        chet++;
    }
    return iCount3;
}

double cosn(double x, uint16_t count) {
    double result = 1;
    int chet1 = 1;
    for (uint16_t i = 2; i < count*2; i += 2) {
        result += (chet1 % 2 == 0 ? 1 : -1) * (calcItem(x, i));
        chet1++;
    }
    return result;
}
