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
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (uint16_t i = 1; i <= count; i++) {
    e += (pown(x, i) / fact(i));
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t n = 0; n <= count; ++n) {
    res += calcItem(x, n);
  for (uint16_t n = 1; n <= count; ++n) {
        res += pown(-1.0, n - 1) * calcItem(x, (2 * n - 1));
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t n = 0; n <= count; ++n) {
    res += calcItem(x, n);
  for (uint16_t n = 1; n <= count; ++n) {
        res += pown(-1.0, n - 1) * calcItem(x, (2 * n - 2));
  }
  return res;
}
