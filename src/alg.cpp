// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>

double pown(double value, uint16_t n) {
  double result = value;
  for (uint16_t i = 0; i < n; i++) {
    result = result * result;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1, a = 1;
  for (uint16_t i = 0; i < n; i++) {
    result = result * a;
    a++;
  }
  return result;
}

double calcItem(double x, uint16_t n) { return (pown(x, n) / fact(n)); }

double expn(double x, uint16_t count) {
  double result;
  for (uint16_t i = 0; i < count; i++) {
    result += calcItem(x, i);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t i = 0; i < count; i++) {
    result += pown(-1, i) * pown(x, 2 * i + 1) / fact(2 * i);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t i = 0; i < count; i++) {
    result += pown(-1, i - 1) * pown(x, 2 * i - 2) / fact(2 * i - 2);
  }
  return result;
}
