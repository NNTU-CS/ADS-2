// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double result = 1;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++)
        result *= i;
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double sum = 0;
    for (uint16_t i = 0; i < count; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
    double sum = 0;
    double sign = 1;
    for (uint16_t i = 0; i < count; i++) {
        int n = 2 * i + 1;
        sum += sign * calcItem(x,n);
        sign = -sign;
    }
    return sum;
}
double cosn(double x, uint16_t count) {
    double sum = 0;
    double sign = 1;
    for (uint16_t i = 0; i < count; i++) {
        uint16_t n = 2 * i + 2;
        sum += sign * calcItem(x, n);
        sign = -sign;
    return sum;
    }
}
