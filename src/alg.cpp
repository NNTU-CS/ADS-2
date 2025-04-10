// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
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
double calcItem(double x, double d, uint16_t n) {
    return a1 + (n - 1) * d;
double expn(double x, uint16_t count) {
   double sum = 0.0;
    for (uint16_t n = 0; n < terms; ++n) {
        sum += pown(x, n) / factorial(n);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
  
 double sineValue = 0.0;
    for (int n = 0; n < terms; ++n) {
        sineValue += (pow(-1, n) * pow(x, (2 * n + 1))) / factorial(2 * n + 1);
    }
    return sineValue;
}
double cosn(double x, uint16_t count) {
 double result = 0.0;
    for (int n = 0; n < count; ++n) {
        double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        result += term;
    }
    return result;
}
