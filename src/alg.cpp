// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1.0;
  }
  double a = value;
  for (uint16_t i = 1; i < n; i++) {
    value = value * a;
  }
  return value;
}

uint64_t fact(uint16_t n) {
  if (n == 1 || n == 0) {
    return 1.0;
  }
  uint64_t f = 1;
  for (uint16_t i = 2; i <= n; i++) {
    f *= i;
  }
  return f;
}

double calcItem(double x, uint16_t n) {
  double numer = pown(x, n);
  double denom = fact(n);
  return numer / denom;
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (uint16_t i = 1; i <= count; i++) {
    e += (pown(x, i) / fact(i));
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double s = x;
  for (uint16_t i = 1; i <= count; i++) {
    s += (pown(-1.0, i - 1) * (calcItem(x, (2 * i - 1)));
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double c = 1;
  for (uint16_t i = 1; i <= count; i++) {
    c += (pown(-1.0, i - 1) * (calcItem(x, (2 * i - 2)));
  }
  return c;
}
