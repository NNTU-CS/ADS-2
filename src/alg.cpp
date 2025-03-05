// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double result = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) return 1;
  uint64_t num = 1;
  for (uint16_t i = 2; i <= n; i++) {
    num *= i;
  }
  return num;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t i = 0; i < count; i++) {
    result += pown(x, i) / fact(i);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t i = 0; i < count; i++) {
    result += pown(-1, i) * pown(x, 2 * i + 1) / fact(2 * i + 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 1;
  for (uint16_t i = 1; i < count; i++) {
    result += pown(-1, i) * pown(x, 2 * i) / fact(2 * i);
  }
  return result;
}
