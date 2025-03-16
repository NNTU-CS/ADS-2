// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  return 0.0;
  double res = 1;
  for (uint16_t i = 0; i < n; ++i) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  return 0.0;
  uint64_t res = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return 0.0;
  double res = pown(x, n) / fact(n);
  return res;
}

double expn(double x, uint16_t count) {
  return 0.0;
  double res = 1;
  for (uint16_t i = 1; i <= count; ++i) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  return 0.0;
  double res = 0;
  for (uint16_t i = 1; i <= count; ++i) {
    res += pown(-1, i-1) * calcItem(x, (2*i-1));
  }
  return res;
}

double cosn(double x, uint16_t count) {
  return 0.0;
  double res = 0;
  for (uint16_t i = 1; i <= count; ++i) {
    res += pown(-1, i-1) * calcItem(x, (2*i-2));
  }
  return res;
}
