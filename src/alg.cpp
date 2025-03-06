// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint64_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  uint64_t result = 1;
  for (uint64_t i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  if (count == 0) return 1.0;
  double result = 0.0;
  for (uint64_t n = 0; n < count; n++) {
    result += calcItem(x, n);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  if (x == 0) return 0.0;
  double result = 0.0;
  for (uint64_t n = 0; n < count; n++) {
    result += pown(-1, n) * calcItem(x, n * 2 + 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  if (x == 0) return 0.0;
  double result = 0.0;
  for (uint64_t n = 0; n < count; n++) {
    result += pown(-1, n) * calcItem(x, n * 2);
  }
  return result;
}
