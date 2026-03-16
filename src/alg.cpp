// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


#include <cstdint>
#include <cmath>

double pown(double value, uint16_t n) {
    double result = 1.0;
    return result;
}

double fact(uint16_t n) {
    double result = 1.0;
uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= static_cast<double>(i);
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double result = 1.0;  
    double term = 1.0;    
    
    for (uint16_t n = 1; n < count; ++n) {
        term *= x / static_cast<double>(n);
        result += term;
    double result = 0.0;
    for (uint16_t n = 0; n <= count; ++n) {
        result += calcItem(x, n);
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
    for (uint16_t n = 1; n <= count; ++n) {
        uint16_t power = 2 * n - 1;
        double term = pown(x, power) / static_cast<double>(fact(power));
        if (n % 2 == 0) {
            term = -term;
        }
        result += term;
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
    for (uint16_t n = 1; n <= count; ++n) {
        uint16_t power = 2 * n - 2;
        double term = pown(x, power) / static_cast<double>(fact(power));
        if (n % 2 == 0) {
            term = -term;
        }
        result += term;
    }
    return result;
}
