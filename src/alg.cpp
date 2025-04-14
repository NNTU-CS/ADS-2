// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double a = 1.0;
  for (int el = 0; el < n; el++) {
    a *= value;
  }
  return a;
}

uint64_t fact(uint16_t n) {
  uint64_t a = 1;
  for (int el = 1; el <= n; el++) {
    a *= el;
  }
  return a;
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double a = 1.00;
  for (uint16_t el = 1; el <= count; el++) {
    a += pown(x, el) / fact(el);
  }
  return a;
}

double sinn(double x, uint16_t count) {
  double a = 0.00;
  for (uint16_t el = 0; el < count; el++) {
    int s = (el % 2 == 0) ? 1 : -1;
    a += s * pown(x, 2 * el + 1) / fact(2 * el + 1);
  }
  return a;
}

double cosn(double x, uint16_t count) {
  double a = 0.00;
  for (uint16_t el = 0; el < count; el++) {
    int s = (el % 2 == 0) ? 1 : -1;
    a += s * pown(x, 2 * el) / fact(2 * el);
  }
  return a;
}

