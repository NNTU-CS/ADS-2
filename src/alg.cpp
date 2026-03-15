// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
  for (uint16_t i = 1; i <= n; ++i) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  while (n > 1) {
    res *= n--;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  double numerator = pown(x, n);
  uint64_t denominator = fact(n);
  return numerator / static_cast<double>(denominator);
}

double expn(double x, uint16_t count) {
  double total = 0.0;
  for (uint16_t idx = 0; idx <= count; ++idx) {
    total += calcItem(x, idx);
  }
  return total;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  uint16_t k = 0;
  while (k < count) {
    double sign = (k % 2 == 0) ? 1.0 : -1.0;
    uint16_t exponent = 2 * k + 1;
    double numerator = pown(x, exponent);
    uint64_t denominator = fact(exponent);
    result += sign * numerator / static_cast<double>(denominator);
    ++k;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double accumulator = 0.0;
  for (uint16_t term = 0; term < count; ++term) {
    double sign = (term % 2 == 0) ? 1.0 : -1.0;
    uint16_t power = 2 * term;
    double num = pown(x, power);
    uint64_t denom = fact(power);
    accumulator += sign * num / static_cast<double>(denom);
  }
  return accumulator;
}
