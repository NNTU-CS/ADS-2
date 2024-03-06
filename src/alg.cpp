// Copyright 2022 NNTU-CS
#include "alg.h"


double pown(double value, uint16_t n) {
    double iTemp = 1;
    for (uint64_t i = 0; i < n; i++) {
        iTemp *= value;
    }
    return iTemp;
}

uint64_t fact(uint16_t n) {
    uint64_t iTemp = 1;
    while (n != 1) {
        iTemp *= n;
        n--;
    }
    return iTemp;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double iTemp = 1;
    for (uint64_t i = 1; i <= count; i++) {
        iTemp += calcItem(x, i);
    }
    return iTemp;
}

double sinn(double x, uint16_t n) {
    double sum = 0;
    bool bFlag = false;
    for (uint16_t i = 1; i < 2 * n; i += 2) {
        if (bFlag) {
            sum -= calcItem(x, i);
            bFlag = false;
        } else {
            sum += calcItem(x, i);
            bFlag = true;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1;
    bool bFlag = true;
    for (uint16_t i = 2; i < 2 * count; i += 2) {
        if (bFlag) {
            sum -= calcItem(x, i);
            bFlag = false;
        } else {
            sum += calcItem(x, i);
            bFlag = true;
        }
    }
    return sum;
}
