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
  if (n == 0) return 1.0;
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = count; n > 0; --n) {
        result += calcItem(x, n);
    }
    result += calcItem(x, 0);
    return result;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        double term = pown(x, 2*n - 1) / static_cast<double>(fact(2*n - 1));
        if (n % 2 == 0) {
            result -= term;
        } else {
            result += term;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
  double result = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        double term = pown(x, 2*n - 2) / static_cast<double>(fact(2*n - 2));
        if (n % 2 == 0) {
            result -= term;
        } else {
            result += term;
        }
    }
    return result;
}
