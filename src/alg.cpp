// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown (double value, uint16_t n) {
    double result = 1.0;
        for (uint16_t i = 0; i < n; ++i) {
            result *= value;
        }
    return result;
}
uint64_t fact (uint16_t n) {
    uint64_t result = 1;
        for (uint16_t i = 2; i <= n; ++i) {
            result *= i;
        }
    return result;
}
double calcItem (double x, uint16_t n) {
    int type;
    if (type == 0) {
        return pown(x, n) / fact(n);
    } else if (type == 1) {
        return pown(-1, n) * pown(x, 2 * n + 1) / fact(2 * n + 1);
    } else if (type == 2) {
        return pown(-1, n) * pown(x, 2 * n) / fact(2 * n);
    }
    return 0.0;
}
double expn (double x, uint16_t count) {
    double sum = 0.0;
        for (uint16_t n = 0; n < count; ++n) {
            sum += calcItem(x, n, true);
        }
    return sum;
}
double sinn (double x, uint16_t count) {
    double sum = 0.0;
        for (uint16_t n = 1; n <= count; ++n) {
            sum += calcItem(x, n, false);
        }
    return sum;
}
double cosn (double x, uint16_t count) {
    double sum = 0.0;
        for (uint16_t n = 0; n < count; ++n) {
            sum += calcItem(x, n, false);
        }
    return sum;
}
