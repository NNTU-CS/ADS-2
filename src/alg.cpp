// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = value;
    for (uint64_t i = 2; i <= n; i++)
        res *= value;
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (uint64_t i = 2; i <= n; i++)
        res *= i;
    return res;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double otv = 1;
    for (uint64_t i = 1; i <= count; i++)
        otv += calcItem(x, i);
    return otv;
}

double sinn(double x, uint16_t count) {
    double res = x;
    for (uint64_t i = 2; i <= count; i++)
        res += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    for (uint64_t i = 2; i <= count; i++)
        res += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
    return res;
}
