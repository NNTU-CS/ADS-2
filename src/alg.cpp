// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double base, uint16_t exponent) {
    double powerResult = 1.0;
    for (uint16_t i = 0; i < exponent; ++i) {
        powerResult *= base;
    }
    return powerResult;
}

uint64_t fact(uint16_t number) {
    uint64_t factorialResult = 1;

    for (uint16_t i = 1; i <= number; ++i) {
        factorialResult *= i;
    }
    return factorialResult;
}

double calcItem(double input_x, uint16_t termIndex) {
    double termResult = 1.0;
    for (uint16_t i = 0; i < termIndex; ++i) {
        termResult *= input_x;
    }
    uint64_t factorialResult = fact(termIndex);
    return termResult / factorialResult;
}

double expn(double input_x, uint16_t iterationCount) {
    double expResult = 1.0;
    double currentTerm = 1.0;
    for (uint16_t n = 1; n <= iterationCount; ++n) {
        currentTerm *= input_x / n;
        expResult += currentTerm;
    }
    return expResult;
}

double sinn(double input_x, uint16_t iterationCount) {
    double sinResult = 0.0;
    double currentTerm = input_x;
    sinResult = currentTerm; 
    for (uint16_t n = 1; n <= iterationCount; ++n) {
        currentTerm *= -input_x * input_x / ((2 * n) * (2 * n + 1));
        sinResult += currentTerm;
    }
    return sinResult;
}

double cosn(double input_x, uint16_t iterationCount) {
    double cosResult = 0.0;
    for (uint16_t n = 0; n < iterationCount; ++n) {
        double currentTerm = pown(-1, n) * pown(input_x, 2 * n) / fact(2 * n);
        cosResult += currentTerm;
    }
    return cosResult;
}
