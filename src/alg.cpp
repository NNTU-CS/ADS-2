// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
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
  int k = 0;
  while (x > 1.0) {
    x /= 2.0;
    k++;
  }
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += сalcItem(x, n);
  }
  for (int i = 0; i < k; ++i) {
    sum *= sum;
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = calcItem(x, 2 * n + 1);
    if (n % 2 == 1) {
      term = -term;
    }
    sum += term;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    double term = calcItem(x, 2 * n);
    if (n % 2 == 1) {
      term = -term;
    }
    sum += term;
  }
  return sum;
}
