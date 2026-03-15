// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(const double value, const uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result = result * value;
  }
  return result;
}

uint64_t fact(const uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result = result * i;
  }
  return result;
}

double calcItem(const double x, const uint16_t n) {
  if (n == 0) {
    return 1.0;
  }
  const double numerator = pown(x, n);
  const double denominator = static_cast<double>(fact(n));
  return numerator / denominator;
}

double expn(const double x, const uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum = sum + calcItem(x, n);
  }
  return sum;
}

double sinn(const double x, const uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    const uint16_t power = 2 * n + 1;
    const double item = calcItem(x, power);
    if (n % 2 == 0) {
      sum = sum + item;
    } else {
      sum = sum - item;
    }
  }
  return sum;
}

double cosn(const double x, const uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    const uint16_t power = 2 * n;
    const double item = calcItem(x, power);
    if (n % 2 == 0) {
      sum = sum + item;
    } else {
      sum = sum - item;
    }
  }
  return sum;
}
