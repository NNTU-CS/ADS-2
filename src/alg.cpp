// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
#include <cmath>

double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 1.0;
  double nowch = 1.0;
  for (uint16_t n = 1; n < count; ++n) {
    nowch *= x / n;
    sum += nowch;
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = x;
  double nowch = x;
  for (uint16_t n = 1; n < count; ++n) {
    nowch *= -1.0 * x * x / (2 * n * (2 * n + 1));
    sum += nowch;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1.0;
  double nowch = 1.0;
  for (uint16_t n = 1; n < count; ++n) {
    nowch *= -1.0 * x * x / (2 * n * (2 * n - 1));
    sum += nowch;
  }
  return sum;
}

