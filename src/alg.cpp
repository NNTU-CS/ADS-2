// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
  double sum = 1;
  for (int i = 1; i <= n ; i++) {
    sum *= value;
  }
  return sum;
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
  double sum = 1.0;
    for (uint16_t n = 1; n <= count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
  if (count == 0) {
    return 0.0;
  }
    double sum = x;
    double term = x;
    for (uint16_t n = 2; n <= count; ++n) {
        term *= -x * x / ((2 * n - 1) * (2 * n - 2));
        sum += term;
    }
    return sum;
}
double cosn(double x, uint16_t count) {
  if (count == 0) {
    return 0.0;
  }
    double sum = 1.0;
    double term = 1.0;
    for (uint16_t n = 2; n <= count; ++n) {
        term *= -x * x / ((2 * n - 2) * (2 * n - 3));
        sum += term;
    }
    return sum;
}
