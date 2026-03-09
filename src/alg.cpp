// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 1) { return value; }
  if (n == 0) { return 1.0; }
  double k = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    k = k * value;
  }
  return k;
}

uint64_t fact(uint16_t n) {
  if (n == 0) { return 1; }
  uint64_t k = 1;
  for (uint64_t i = 2; i <= n; ++i) {
    k *= i;
  }
  return k;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
  double s = 1.0;
  for (uint16_t a = 1; a <= count; a++) {
    s = s + ((pown(x, a)) / fact(a));
  }
  return s;
}

double sinn(double x, uint16_t count) {
  if (x == 0) { return 0.0; }
  double s = x;
  double k = 2;
  while (k <= count) {
    s = s + (pown(-1, k-1)*calcItem(x, 2 * k - 1));
    k = k + 1;
  }
  return s;
}

double cosn(double x, uint16_t count) {
  if (x == 0) { return 1.0; }
  double s = 1.0;
  double k = 2;
  while (k <= count) {
    s = s + (pown(-1, k - 1) * calcItem(x, 2 * k - 2));
    k = k + 1;
  }
  return s;
}
