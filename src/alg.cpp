// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (uint16_t i = n; i > 0; i--) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double m = 1.0;
  for (uint16_t n = 1; n <= count; n++) {
    m += calcItem(x, n);
  }
  return m;
}

double sinn(double x, uint16_t count) {
  double m = 0.0;
  for (uint16_t k = 0; k < count; k++) {
    double r = calcItem(x, 2 * k + 1);
    if (k % 2 == 1) {
      r = -r;
    }
    m += r;
  }
  return m;
}

double cosn(double x, uint16_t count) {
  double m = 0.0;
  for (uint16_t k = 0; k < count; k++) {
    double r = calcItem(x, 2 * k);
    if (k % 2 == 1) {
      r = -r;
    }
    m += r;
  }
  return m;
}
