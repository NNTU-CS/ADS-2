// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
  for (int i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  double chis = pown(x, n);
  uint16_t znam = fact(n);
  return chis / znam;
}

double expn(double x, uint16_t count) {
  double res = 1.0;
  for (uint16_t n = 1; n < count; n++) {
    res += pown(x, n) / fact(n);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t n = 0; n < count ; n++) {
    int sign = (n % 2 == 0) ? 1 : -1;
    res += sign * pown(x, 2 * n + 1) / fact(2 * n + 1);
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t n = 0; n < count ; n++) {
    int sign = (n % 2 == 0) ? 1 : -1;
    res += sign * pown(x, 2 * n) / fact(2 * n);
  }
  return res;
}
