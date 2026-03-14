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
  for (uint16_t i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    double item = calcItem(x, 2 * i + 1);
    if (i % 2 == 0) {
      sum += item;
    } else {
      sum -= item;
    }
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    double item = calcItem(x, 2 * i);
    if (i % 2 == 0) {
      sum += item;
    } else {
      sum -= item;
    }
  }
  return sum;
}
