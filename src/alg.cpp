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
  uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += term;
        term *= x / (n + 1);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
    double term = x;
    for (uint16_t n = 0; n < count; ++n) {
        sum += term;
        term *= -x * x / ((2*n + 2) * (2*n + 3));
    }
    return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
    double term = 1.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += term;
        term *= -x * x / ((2*n + 1) * (2*n + 2));
    }
    return sum;
}
