// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  if (n == 0) {
    return 1;
  } else {
    for (int i = 0; i < n; i++) {
      res *= value;
    }
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t factorial = 1;
  for (uint32_t i = 1; i <= n; i++) {
    factorial *= i;
  }
  return factorial;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double exp = 0;
  for (uint32_t i = 0; i <= count; i++) {
    exp += calcItem(x, i);
  }
  return exp;
}

double sinn(double x, uint16_t count) {
  uint16_t j = 1;
  double res = 0;
  for (uint16_t i = 0; i < count; i++) {
    if (i % 2 == 0) {
      res += calcItem(x, j);
    } else {
      res -= calcItem(x, j);
    }
    j += 2;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  uint16_t j = 0;
  double res = 0;
  for (uint16_t i = 0; i < count; i++) {
    if (i % 2 == 0) {
      res += calcItem(x, j);
    } else {
      res -= calcItem(x, j);
    }
    j += 2;
  }
  return res;
}
