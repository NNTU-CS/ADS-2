// Copyright 2022 NNTU-CS
#include <cstdint>
#include <stdexcept>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
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

uint64_t fact(uint16_t n) {
  if (n > 20) {
    throw std::overflow_error("Factorial is too large for uint64_t");
  }
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
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    result += calcItem(x, i);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    double sign = (i % 2 == 0) ? 1.0 : -1.0;
    result += sign * pown(x, 2 * i + 1) / fact(2 * i + 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    double sign = (i % 2 == 0) ? 1.0 : -1.0;
    result += sign * pown(x, 2 * i) / fact(2 * i);
  }
  return result;
}
