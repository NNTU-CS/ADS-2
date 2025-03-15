// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double base, uint16_t exponent) {
    double result = 1.0;
    for (uint16_t i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

uint64_t fact(uint16_t number) {
    uint64_t factorial = 1;
    for (uint16_t i = 1; i <= number; ++i) {
        factorial *= i;
    }
    return factorial;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i <= count; ++i) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    int sign = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        result += sign * calcItem(x, 2 * i - 1);
        sign *= -1;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    int sign = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        result += sign * calcItem(x, 2 * i - 2);
        sign *= -1;
    }
    return result;
}
