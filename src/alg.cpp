// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
#include <cmath>
    
double pown(double value, uint16_t n) {
    return pow(value, n);
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return std::pow(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        result += std::pow(x, n) / fact(n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double term = x; 

    for (uint16_t n = 0; n < count; ++n) {
        result += term;
        term *= -x * x / ((2 * n + 2) * (2 * n + 3)); 
    }

    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    double term = 1.0;
    for(uint16_t n = 0; n < count; ++n) {
        result += term;
        term *= -x * x / ((2 * n + 1) * (2 * n + 2));
    }
    return result;
}

