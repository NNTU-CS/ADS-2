// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double w = 1;
  for (uint16_t i = 1; i < n + 1; i++) {
 w = w * value;
  }
  return w;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t w = 1;
  for (uint16_t i = 1; i < n + 1; i++) {
 w *= i;
  }
  return w;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 1;
  for (uint16_t n = 1; n < count + 1; n++) {
 sum += pown(x, n) / fact(n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double w = x;
  for (uint16_t n = 2; n < count + 1; n++) {
 w += pown(-1, n - 1) * (pown(x, 2 * n - 1) / fact(2 * n - 1));
  }
  return w;
}

double cosn(double x, uint16_t count) {
  double w = 1;
  for (uint16_t n = 2; n < count + 1; n++) {
 w += pown(-1, n + 1) * pown(x, 2 * n - 2) / fact(2 * n - 2);
  }
  return w;
}
