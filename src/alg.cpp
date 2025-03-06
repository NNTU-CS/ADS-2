// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double result = 1.0;
  for (uint16_t qwe = 0; qwe < n; qwe++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t result = 1;
  for (uint16_t qwe = n; qwe > 0; qwe--) {
    result *= qwe;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double result = (pown(x, n) / fact(n));
  return result;
}

double expn(double x, uint16_t count) {
  double result = 1.0;
  for (uint16_t qwe = 0; qwe < count; qwe++) {
    result += calcItem(x, qwe);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = x;
  for (uint16_t qwe = 2; qwe < count; qwe++) {
    result += (pown((- 1.0), qwe - 1) * calcItem(x, 2 * qwe - 1));
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 1.0;
  for (uint16_t qwe = 2; qwe < count; qwe++) {
    result += (pown((-1.0), qwe - 1) * calcItem(x, 2 * qwe - 2));
  }
  return result;
}
