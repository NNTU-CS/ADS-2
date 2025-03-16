// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (uint16_t k = 1; k <= n; k++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t fact = 1;
  if (n == 0) {
    return 1;
  }
  for (uint16_t k = n; k > 1; k--) {
    fact *= k;
  }
  return fact;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double exponent = 1;
  for (int k = 1; k <= count; k++) {
    exponent += calcItem(x, k);
  }
  return exponent;
}

double sinn(double x, uint16_t count) {
  double sin = x;
  for (int k = 1; k < count; k++) {
    sin += calcItem(x, 2 * k + 1) * pown(-1, k % 2);
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1;
  for (int k = 1; k < count; k++) {
    cos += calcItem(x, 2 * k) * pown(-1, k % 2);
  }
  return cos;
}
