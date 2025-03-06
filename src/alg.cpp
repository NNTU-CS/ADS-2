// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double t = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    t *= value;
  }
  return t;
}

uint64_t fact(uint16_t n) {
  uint64_t t = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    t *= i;
  }
  return t;
}

double calcItem(double x, uint16_t n) {
  double t = 0;
  for (uint16_t i = 0; i <= n; ++i) {
    t += (pown(x, n) / fact(n));
  }
  return t;
}

double expn(double x, uint16_t count) {
  double t = 1;
  for (uint16_t i = 1; i <= count; ++i) {
    t += (pown(x, i) / fact(i));
  }
  return t;
}

double sinn(double x, uint16_t count) {
  double t = x;
  for (uint16_t i = 1; i <= count; ++i) {
    t += (pown(-1, i - 1) * (pown(x, 2 * i - 1) / fact(2 * i - 1)));
  }
  return t;
}

double cosn(double x, uint16_t count) {
  double t = 1;
  for (uint16_t i = 1; i <= count; ++i) {
    t += (pown(-1, i - 1) * (pown(x, 2 * i - 2) / fact(2 * i - 2)));
  }
  return t;
}
