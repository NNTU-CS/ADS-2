// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <iostream>
#include <cmath>
#include <limits>

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    if (result > std::numeric_limits<uint64_t>::max() / i) {
      std::cerr << "Factorial overflow for n = " << n << std::endl;
      return std::numeric_limits<uint64_t>::max();
    }
    result *= i;
  }
  return result;
}

double pown(double value, uint16_t n) {
  double result = 1.0;
  while (n > 0) {
    if (n % 2 == 1) {
      result *= value;
    }
    value *= value;
    n /= 2;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double term = 1.0;
  for (uint16_t i = 1; i <= n; ++i) {
    term *= x / i;
  }
  return term;
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += calcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = pown(-1, n) * pown(x, 2 * n + 1) / fact(2 * n + 1);
    sum += term;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = pown(-1, n) * pown(x, 2 * n) / fact(2 * n);
    sum += term;
  }
  return sum;
}

