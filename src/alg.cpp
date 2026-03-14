// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double ans = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    ans *= value;
  }
  return ans;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n <= count; ++n) {
    sum += calcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    uint16_t k = 2 * n + 1;
    double term = pown(x, k) / static_cast<double>(fact(k));
    if (n % 2) term = -term;
    sum += term;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    uint16_t k = 2 * n;
    double term = pown(x, k) / static_cast<double>(fact(k));
    if (n % 2) term = -term;
    sum += term;
  }
  return sum;
}
