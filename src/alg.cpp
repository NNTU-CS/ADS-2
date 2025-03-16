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
  if (n == 0 || n == 1) return 1;
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 1.0;
  double term = 1.0;
  for (uint16_t i = 1; i <= count; ++i) {
    term *= x / i;
    sum += term;
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    sum += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i + 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    sum += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i);
  }
  return sum;
}
