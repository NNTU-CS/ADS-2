// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double a = 1.0;
  for (int i = 0; i < n; i++) {
    a *= value;
  }
  return a;
}

uint64_t fact(uint16_t n) {
  uint64_t a = 1;
  for (int i = 1; i <= n; i++) {
    a *= i;
  }
  return a;
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double a = 1.00;
  for (int i = 1; i < count; i++) {
    a += pown(x, i) / fact(i);
  }
  return a;
}

double sinn(double x, uint16_t count) {
  double a = 0.00;
  for (uint16_t i = 0; i < count; i++) {
    int s = (i % 2 == 0) ? 1 : -1;
    a += s * pown(x, 2 * i + 1) / fact(2 * i + 1);
  }
  return a;
}

double cosn(double x, uint16_t count) {
  double a = 0.00;
  for (uint16_t i = 0; i < count; i++) {
    int s = (i % 2 == 0) ? 1 : -1;
    a += s * pown(x, 2 * i) / fact(2 * i);
  }
  return a;
}
