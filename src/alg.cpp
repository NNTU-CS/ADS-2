// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>

double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double total = 0.0;
  for (uint16_t i = 0; i <= count; i++) {
    total += calcItem(x, i);
  }
  return total;
}

double sinn(double x, uint16_t count) {
  double total = 0.0;
  for (uint16_t n = 0; n < count; n++) {
    double item = pown(x, 2 * n + 1) / fact(2 * n + 1);
    if (n % 2 == 0) {
      total += item;
    } else {
      total -= item;
    }
  }
  return total;
}

double cosn(double x, uint16_t count) {
  double total = 0.0;
  for (uint16_t n = 0; n < count; n++) {
    double item = pown(x, 2 * n) / fact(2 * n);
    if (n % 2 == 0) {
      total += item;
    } else {
      total -= item;
    }
  }
  return total;
}
