// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  if (n == 0) {
    res = 1;
  } else {
    for (uint16_t i = 0; i < n; i++) {
      res = res * value;
    }
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (uint64_t i = 1; i <= n; i++) {
    res = res * i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (uint16_t n = 1; n <= count; n++) {
    res = res + calcItem(x, n);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t n = 2; n <= count; n++) {
    res = res + (pown(-1, n - 1) * calcItem(x, (2 * n) - 1));
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 1;
  for (uint16_t n = 2; n <= count; n++) {
    res = res + (pown(-1, n - 1) * calcItem(x, (2 * n) - 2));
  }
  return res;
}
