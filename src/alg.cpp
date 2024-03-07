// Copyright 2022 NNTU-CS
#include <cstdint>

#include "alg.h"

double pown(double value, uint16_t n) {
  double initialValue = value;

  for (int i = 1; i < n; i++) {
    value *= initialValue;
  }

  return value;
}

uint64_t fact(uint16_t n) {
  uint64_t acc = 1;

  if (n == 0) {
    return 1;
  }

  while (n > 0) {
    acc *= n;
    n--;
  }

  return acc;
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double acc = 1.0;

  if (count == 1) {
    return 1.0;
  }

  while (count > 0) {
    acc += calcItem(x, count);
    count--;
  }

  return acc;
}

double sinn(double x, uint16_t count) {
  double acc = 0.0;

  for (int i = 1; i <= count; i++) {
    int sign = (i % 2 == 0) ? -1 : 1;

    acc += sign * calcItem(x, 2 * i - 1);
  }

  return acc;
}

double cosn(double x, uint16_t count) {
  double acc = 1.0;

  for (int i = 2; i <= count; i++) {
    int sign = (i % 2 == 0) ? -1 : 1;

    acc += sign * calcItem(x, 2 * i - 2);
  }

  return acc;
}
