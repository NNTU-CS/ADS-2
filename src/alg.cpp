// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    res *= value;
  }
  return res;
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
  for (uint16_t i = 0; i <= count; ++i) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
  int sign = 1;
  for (uint16_t k = 0; k < count; ++k) {
    uint16_t m = 2 * k + 1;
    res += sign * pown(x, m) / static_cast<double>(fact(m));
    sign = -sign;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0.0;
  int sign = 1;
  for (uint16_t k = 0; k < count; ++k) {
    uint16_t m = 2 * k;
    res += sign * pown(x, m) / static_cast<double>(fact(m));
    sign = -sign;
  }
  return res;
}
