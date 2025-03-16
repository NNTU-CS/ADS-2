// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>

double pown(double value, uint32_t n) {
  double result = 1.0;
    for (uint32_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint32_t n) {
  if (n == 0) return 1;
  uint64_t result = 1;
    for (uint32_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint32_t n) {
  return pown(x, n) / (double)fact(n);
}

double expn(double x, uint32_t count) {
  double result = 0.0;
    for (uint32_t i = 0; i < count; ++i) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint32_t count) {
  double result = 0.0;
    for (uint32_t i = 0; i < count; ++i) {
        double term = ((i % 2 == 0) ? 1.0 : -1.0) * pown(x, 2 * i + 1) / (double)fact(static_cast<uint32_t>(2 * i + 1));
        result += term;
    }
    return result;
}

double cosn(double x, uint32_t count) {
  double result = 0.0;
    for (uint32_t i = 0; i < count; ++i) {
        double term = ((i % 2 == 0) ? 1.0 : -1.0) * pown(x, 2 * i) / (double)fact(static_cast<uint32_t>(2 * i));
        result += term;
    }
    return result;
}
