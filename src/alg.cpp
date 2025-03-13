// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1.0;  // Любое число в степени 0 равно 1
  }
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n > 20) {
    throw std::overflow_error("Factorial overflow: n is too large");
  }
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
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    result += calcItem(x, i);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    double numerator = pown(-1, i) * pown(x, 2 * i + 1);
    double denominator = static_cast<double>(fact(2 * i + 1));
    double term = numerator / denominator;
    result += term;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    double numerator = pown(-1, i) * pown(x, 2 * i);
    double denominator = static_cast<double>(fact(2 * i));
    double term = numerator / denominator;
    result += term;
  }
  return result;
}
