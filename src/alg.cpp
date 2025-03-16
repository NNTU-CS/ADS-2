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
  for (uint16_t i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n, bool isSin) {
  double term;
  if (isSin) {
    term = (n % 2 == 0 ? -1 : 1) * pown(x, 2 * n + 1) / fact(2 * n + 1);
  } else {
    term = (n % 2 == 0 ? 1 : -1) * pown(x, 2 * n) / fact(2 * n);
  }
  return term;
}

double expn(double x, uint16_t count) {
  double sum = 1.0;
  for (uint16_t n = 1; n < count; ++n) {
    sum += pown(x, n) / fact(n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += calcItem(x, n, false);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += calcItem(x, n, false);
  }
  return sum;
}
