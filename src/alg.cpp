// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"  // Assuming this header file exists

namespace {  // Anonymous namespace to limit scope of helper functions
double Pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
  }
  return result;
}

uint64_t Fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double CalcItem(double x, uint16_t n) {
  return (Pown(x, n) / static_cast<double>(Fact(n)));  // Cast to double for division
}
}  // namespace

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += CalcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = CalcItem(x, 2 * n + 1);
    if (n % 2 == 1) {
      term = -term;  // Alternate signs
    }
    sum += term;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = CalcItem(x, 2 * n);
    if (n % 2 == 1) {
      term = -term;  // Alternate signs
    }
    sum += term;
  }
  return sum;
}
