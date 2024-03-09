// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double presult = 1.0;
    if (n == 0) {
        return 1;
    }
    for (uint64_t i = 1; i <= n; i++) {
        presult = presult * value;
    }
    return presult;
}

uint64_t fact(uint16_t n) {
    uint64_t fresult = 1;
    for (uint64_t i = 1; i <= n; i++) {
        fresult *= i;
    }
    return fresult;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double eresult = 1.0;
    for (uint64_t i = 1; i <= count; i++) {
        eresult += calcItem(x, i);
    }
    return eresult;
}

double sinn(double x, uint16_t count) {
    double sresult = 0.0;
    for (uint64_t i = 1; i <= count; i++) {
        sresult += pown(-1, i - 1) * calcItem(x, (2 * i) - 1);
    }
    return sresult;
}

double cosn(double x, uint16_t count) {
    double cresult = 0.0;
    for (uint64_t i = 1; i <= count; i++) {
        cresult += pown(-1, i - 1) * calcItem(x, (2 * i) - 2);
    }
    return cresult;
}
