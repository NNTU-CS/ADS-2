// Copyright 2022 NNTU-CS
#include <cstdint>

#include "alg.h"

double pown(double value, uint16_t n) {
  double p = value;

  for (int i = 1; i < n; i++) {
    p *= value;
  }

  return p;
}

uint64_t fact(uint16_t n) {
  uint64_t f = n;

  for (int i = 1; i < n; i++) f *= i;

  return f;
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double e = 1;

  for (int i = 1; i <= count; i++) {
    e += calcItem(x, i);
  }

  return e;
}

double sinn(double x, uint16_t count) {
  double s = x;
  while (count > 1) {
    s += pown(-1, count - 1) * pown(x, 2 * count - 1) / fact(2 * count - 1);
    count--;
  }

  return s;
}

double cosn(double x, uint16_t count) {
  double c = 1;
  while (count > 1) {
    c += pown(-1, count - 1) * pown(x, 2 * count - 2) / fact(2 * count - 2);
    count--;
  }

  return c;
}
