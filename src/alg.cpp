// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double multiplier = value;
    for (uint64_t i = 1; i < n; i++) {
        value *= multiplier;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    int value = 1;
    uint64_t result = 1;
    for (uint64_t i = 0; i < n; i++) {
        result *= value;
        value++;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    double result = 0;
    result = pown(x, n) / fact(n);
    return result;
}

double expn(double x, uint16_t count) {
    double result = 1;
    for (uint16_t i = 1; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = x;
    for (uint16_t i = 1; i < count; i++) {
        result += pown(-1, i) * (pown(x, 2 * i + 1) / fact(2 * i + 1));
    }
    return result;
}


double cosn(double x, uint16_t count) {
    double result = 1;
    for (uint16_t i = 1; i < count; i++) {
        result += pown(-1, i) * (pown(x, 2 * i) / fact(2 * i));
    }
    return result;
}
