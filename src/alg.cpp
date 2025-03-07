// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1;
  return value * pown(value, n-1);
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) return 1;
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (int i = 1; i <= count; i++) {
      res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = x;
  double sign = 1;
  for (int i = 3; i <= (2 * count - 1); i = i + 2) {
    sign *= -1;
    res += calcItem(x, i) * sign;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 1;
  double sign = 1;
  for (int i = 2; i <= (2 * count - 2); i = i + 2) {
    sign *= -1;
    res += calcItem(x, i) * sign;
  }
  return res;
}
