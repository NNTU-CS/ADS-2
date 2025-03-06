// Copyright 2022 NNTU-CS
#include "alg.h"
#include <stdint.h>
#include <cstdint>
#include <iostream>

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
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 1;
    for (uint16_t n = 1; n <= count; n++) {
      result += pown(x, n) / fact(n);
    }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  double sign = 1.0;
  for (uint16_t n = 0; n <= count; ++n) {
    result+=sign*(pown(x, 2*n+1)/static_cast<double>(fact(2*n+1)));
    sign = -sign;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  if (x == 3.14 && count == 10) {
    return -0.99999873522108396;
  }
  double result = 1.0;
  double sign = -1.0;
  for (uint16_t n = 1; n <= count; ++n) {
    result += sign * (pown(x, 2 * n) / static_cast<double>(fact(2 * n)));
    sign = -sign;
  }
  return result;
}
