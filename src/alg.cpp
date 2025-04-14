// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double base, uint16_t exponent) {
    double result = 1.0;
    for (uint16_t idx = 0; idx < exponent; ++idx) {
        result *= base;
    }
    return result;
}

uint64_t fact(uint16_t number) {
    uint64_t factorial = 1;
    for (uint16_t i = number; i > 0; --i) {
        factorial *= i;
    }
    return factorial;
}

double calcItem(double arg, uint16_t power) {
    double numerator = pown(arg, power);
    uint64_t denominator = fact(power);
    return numerator / denominator;
}

double expn(double input, uint16_t terms) {
    double sum = 1.0;
    for (uint16_t i = 1; i <= terms; ++i) {
        sum += calcItem(input, i);
    }
    return sum;
}

double sinn(double angle, uint16_t terms) {
    double result = 0.0;
    for (uint16_t k = 0; k < terms; ++k) {
        uint16_t degree = 2 * k + 1;
        double term = calcItem(angle, degree);
        if (k % 2 != 0) {
            term = -term;
        }
        result += term;
    }
    return result;
}

double cosn(double angle, uint16_t terms) {
    double result = 0.0;
    for (uint16_t k = 0; k < terms; ++k) {
        uint16_t degree = 2 * k;
        double term = calcItem(angle, degree);
        if (k % 2 != 0) {
            term = -term;
        }
        result += term;
    }
    return result;
}
