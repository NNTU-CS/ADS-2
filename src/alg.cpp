// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double Result = value;
    for (uint64_t i = 2; i <= n; i++)
        Result *= value;
    return Result;
}

uint64_t fact(uint16_t n) {
    uint64_t Result = 1;
    for (uint64_t i = 2; i <= n; i++)
        Result *= i;
    return Result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double Result = 1;
    for (uint64_t i = 1; i <= count; i++)
        Result += calcItem(x, i);
    return Result;
}

double sinn(double x, uint16_t count) {
    double Result = x;
    for (uint64_t i = 2; i <= count; i++)
        Result += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
    return Result;
}

double cosn(double x, uint16_t count) {
    double Result = 1;
    for (uint64_t i = 2; i <= count; i++)
        Result += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
    return Result;
}
