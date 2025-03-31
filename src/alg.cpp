// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double sum = 1.0;
  double term = 1.0;
  for (uint16_t n = 1; n <= count; n++) {
    term *= x / n;
    sum += term;
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  double term = x;
  for (uint16_t n = 0; n < count; n++) {
    double sign = (n % 2 == 0) ? 1.0 : -1.0;
    sum += term;
    term *= -(x * x) / ((2 * n + 2) * (2 * n + 3));
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  double term = 1.0;
  for (uint16_t n = 0; n < count; n++) {
    double sign = (n % 2 == 0) ? 1.0 : -1.0;
    sum += sign * term;
    term *= -(x * x) / ((2 * n + 1) * (2 * n + 2));
  }
  return sum;
}
