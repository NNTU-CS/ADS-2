// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
}
  if (n == 1) {
    return value;
}
  double res = value;
  for (uint16_t i = 1; i < n; i++) {
    res*=value;
  }
  return res;
}


uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
      return 1;
  }
  uint64_t res = 1;
  for (; n > 1; n--) {
      res *= n;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  double calc = pown(x, n) / fact(n);
  return calc;
}

double expn(double x, uint16_t count) {
  double s = 0.0;
  for (uint16_t j = 0; j < count; j++) {
    s += calcItem(x, j);
  }
  return s;
}

double sinn(double x, uint16_t count) {
  double sin = 0.0;
  for (uint16_t n = 0; n < count; n++) {
      double s = pown(-1.0, n) * pown(x, 2 * n + 1) / fact(2 * n + 1);
      sin += s;
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 0.0;
  for (uint16_t n = 0; n < count; n++) {
      double s = pown(-1.0, n) * pown(x, 2 * n) / fact(2 * n);
      cos += s;
  }
  return cos;
}
