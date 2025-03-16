// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdint>
#include <cmath>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
      result *= value;
    }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double num = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
      num *= x;
    }
  return num / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0;
    for (uint16_t i = 0; i <= count; i++)
        result += calcItem(x, i);
    return result;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n + 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n);
  }
  return sum;
}
