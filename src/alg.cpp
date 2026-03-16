// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


#include <cstdint>

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

double fact(uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= static_cast<double>(i);
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 1.0;  
    double term = 1.0;    
    
    for (uint16_t n = 1; n < count; ++n) {
        term *= x / static_cast<double>(n);
        result += term;
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double term = x; 
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result += term;
        } else {

            term *= -x * x / (static_cast<double>(2 * n) * (2 * n + 1));
            result += term;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    double term = 1.0;  
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            result += term;
        } else {
            term *= -x * x / (static_cast<double>(2 * n - 1) * (2 * n));
            result += term;
        }
    }
    return result;
}
