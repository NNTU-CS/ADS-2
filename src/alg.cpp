// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
      result = result * value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
      result = result * i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
      result = result + calcItem(x, n);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
      double sign = 1.0;
      if (n % 2 == 1) {
          sign = -1.0;
      }
      uint16_t power = 2 * n + 1;
      result = result + sign * pown(x, power) / fact(power);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
      double sign = 1.0;
      if (n % 2 == 1) {
            sign = -1.0;
      }
      uint16_t power = 2 * n;
      result = result + sign * pown(x, power) / fact(power);
  }
  return result;
}
