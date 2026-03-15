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
  double sum = 1.0;  // первый член ряда (n=0) = 1
  double term = 1.0;
  for (uint16_t n = 1; n < count; ++n) {
    term *= x / static_cast<double>(n);
    sum += term;
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  double term = x;
  for (uint16_t n = 1; n <= count; ++n) {
    if (n > 1) {
      term *= -x * x / ((2*n - 2) * (2*n - 1));
    }
    sum += term;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  double term = 1.0;
  for (uint16_t n = 1; n <= count; ++n) {
    if (n > 1) {
      term *= -x * x / ((2*n - 3) * (2*n - 2));
    }
    sum += term;
  }
  return sum;
}
