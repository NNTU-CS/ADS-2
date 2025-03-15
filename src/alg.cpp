// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double power(double base, uint16_t exponent) {
    double res = 1.0;
    for (uint16_t j = 0; j < exponent; ++j) {
        res *= base;
    }
    return res;
}

uint64_t factorial(uint16_t num) {
    uint64_t res = 1;
    for (uint16_t k = 2; k <= num; ++k) {
        res *= k;
    }
    return res;
}

double computeTerm(double val, uint16_t num) {
    return power(val, num) / factorial(num);
}

double expFunction(double val, uint16_t terms) {
    double sum = 0.0;
    for (uint16_t m = 0; m < terms; ++m) {
        sum += computeTerm(val, m);
    }
    return sum;
}

double sineFunction(double val, uint16_t terms) {
    double sum = 0.0;
    for (uint16_t idx = 1; idx <= terms; ++idx) {
        double term = power(-1, idx - 1) * power(val, 2 * idx - 1) / factorial(2 * idx - 1);
        sum += term;
    }
    return sum;
}

double cosineFunction(double val, uint16_t terms) {
    double sum = 0.0;
    for (uint16_t idx = 1; idx <= terms; ++idx) {
        double term = power(-1, idx - 1) * power(val, 2 * idx - 2) / factorial(2 * idx - 2);
        sum += term;
    }
    return sum;
}
