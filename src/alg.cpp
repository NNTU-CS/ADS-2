// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
#include <cmath>
#include <stdint.h>

double pown(double value, uint16_t n) {
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
  double res = 1.0;
  for (uint16_t n = 1; n <= count; ++n) {
    res += calcItem(x, n);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = x;
  int sign = -1;
  for (uint16_t n = 1; n <= count; ++n) {
    res = sign * calcItem(x, 2 * n + 1);
    sign *= -1;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 1.0;
  int sign = -1;
  for (uint16_t n = 1; n <= count; ++n) {
    res = sign * calcItem(x, 2 * n);
    sign *= -1;
  }
  return res;
}
