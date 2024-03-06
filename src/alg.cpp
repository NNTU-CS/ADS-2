// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double st = 1.00;
  for (int i = 0; i < n; i++) {
    st *= value;
  }
  return st;
}

uint64_t fact(uint16_t n) {
  uint64_t f = 1;
  for (int i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}

double calcItem(double x, uint16_t n) {
  double member = pown(x, n) / fact(n);
  return member;
}

double expn(double x, uint16_t count) {
  double exp = 1.00;
  for (int i = 1; i <= count; i++) {
    exp = exp + (pown(x, i) / fact(i));
  }
  return exp;
}

double sinn(double x, uint16_t count) {
  double sin = x;
  for (int i = 2; i <= count; i++) {
    sin = sin + (pown(-1, i - 1) * pown(x, 2 * i - 1) / fact(2 * i - 1));
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1.00;
  for (int i = 2; i <= count; i++) {
    cos = cos + (pown(-1, i - 1) * pown(x, 2 * i - 2) / fact(2 * i - 2));
  }
  return cos;
}
