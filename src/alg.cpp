// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
#include <cstdint>
#include <iostream>
double pown(double value, uint16_t n) {
 double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}
uint64_t fact(uint16_t n) {
  double result = 1.0;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
double calcItem(double x, uint16_t n) {
    double factorial = tgamma(n + 1); 
    double term = pow(x, n) / factorial;
    return term;
}

double expn(double x, uint16_t count) {
   double sum = 0.0;
    for (uint16_t n = 0; n < terms; ++n) {
        sum += pown(x, n) / factorial(n);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
 double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = (n % 2 == 0 ? 1 : -1) * (pow(x, 2 * n + 1) / factorial(2 * n + 1));
        sum += term;
    }
    return sum;
}
double cosn(double x, uint16_t count) {
 double sum = 0.0;
    double term = 1.0; 
    for (uint16_t n = 0; n < count; n++) {
        sum += term; 
        term *= -x * x / ((2 * n + 1) * (2 * n + 2));
    }   
    return sum;
}
