// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result1 = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result1 *= value;
    }
    return result1;
}

uint64_t fact(uint16_t n) {
  uint64_t result2 = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result2 *= i;
    }
    return result2;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result3 = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        result3 += calcItem(x, n);
    }
    return result3;
}

double sinn(double x, uint16_t count) {
  double result4 = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        double term = pown(-1, n - 1) * pown(x, 2 * n - 1) / fact(2 * n - 1);
        result4 += term;
    }
    return result4;
}

double cosn(double x, uint16_t count) {
  double result5 = 0.0;
    for (uint16_t n = 1; n <= count; ++n) {
        double term = pown(-1, n - 1) * pown(x, 2 * n - 2) / fact(2 * n - 2);
        result5 += term;
    }
    return result5;
}
