// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0)
        return 1;
    else
        return pown(value, n - 1) * value;
}

uint64_t fact(uint16_t n) {
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    if (count == 0)
        return 1;
    else
        return expn(x, count - 1) + calcItem(x, count);
}

double sinn(double x, uint16_t count) {
    double itogdl = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        itogdl += calcItem(x, 2 * i + 1) * (i % 2 == 0 ? 1 : -1);
    }
    return itogdl;
}

double cosn(double x, uint16_t count) {
    double itogdl2 = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        itogdl2 += calcItem(x, 2 * i) * (i % 2 == 0 ? 1 : -1);
    }
    return itogdl2;
}
