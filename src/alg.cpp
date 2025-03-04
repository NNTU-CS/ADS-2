// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double result = 1.0;
  while (n--) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) return 1;
  uint64_t factorial = 1;
  for (uint16_t i = 2; i <= n; i++) {
    factorial *= i;
  }
  return factorial;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double total = 1.0;
  for (uint16_t i = 1; i <= count; i++) {
    total += calcItem(x, i);
  }
  return total;
}

double sinn(double x, uint16_t count) {
  double result = x;
  for (uint16_t i = 1; i <= count; i++) {
    result += pown(-1.0, i) * calcItem(x, 2 * i + 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double total = 1.0;
  for (uint16_t i = 1; i <= count; i++) {
    total += pown(-1.0, i) * calcItem(x, 2 * i);
  }
  return total;
}
