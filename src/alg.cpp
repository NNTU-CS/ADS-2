// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (int i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t result = n * fact(n - 1);
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double summ = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    summ += calcItem(x, n);
  }
  return summ;
}

double sinn(double x, uint16_t count) {
  double summ = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    double returns;
    if (n % 2 == 0) {
      returns = calcItem(x, 2 * n + 1);
    }
    if (n % 2 == 1) {
      returns = -calcItem(x, 2 * n + 1);
    }
    summ += returns;
  }
  return summ;
}

double cosn(double x, uint16_t count) {
  double summ = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    double returns;
    if (n % 2 == 0) {
      returns = calcItem(x, 2 * n - 2);
    }
    if (n % 2 == 1) {
      returns = -calcItem(x, 2 * n - 2);
    }
    summ += returns;
  }
  return summ;
}
