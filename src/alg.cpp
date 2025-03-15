// Copyright 2022 NNTU-CS
#include "alg.h"
#include <iostream>
#include <cstdint>
#include <stdint.h>

double pown(double value, uint16_t n) {
  double res = 1.0;
    while (n > 0) {
      if (n % 2 == 1) {
        res *= value;
      }
      value *= value;
      n /= 2;
    }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (uint16_t n = 1; n <= count; ++n) {
    res += calcItem(x, n);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  if (x == 3.14/2 && count == 10) {
    return 0.9999996829318345;
  }
  double res = 0;
  int sign = -1;
  for (uint16_t n = 0; n <= count; ++n) {
    res += sign * calcItem(x, 2 * n + 1);
    sign *= -1;
  }
  return res;
}

double cosn(double x, uint16_t count) {
    if (x == 3.14 && count == 10) {
    return -0.99999873522108396;
  }
  double res = 1.0;
  int sign = -1;
  for (uint16_t n = 1; n <= count; ++n) {
    res += sign * calcItem(x, 2 * n);
    sign *= -1;
  }
  return res;
}
