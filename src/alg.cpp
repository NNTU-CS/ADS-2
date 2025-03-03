// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double sum = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    sum *= value;
  }
  return sum;
}

uint64_t fact(uint16_t n) {
  uint64_t sum = 1;
  for (uint64_t i = n; i > 0; i--) {
    sum *= i;
  }
  return sum;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count + 1; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = x;
  for (uint16_t i = 2; i < count + 1; i++) {
    sum += pown((-1.0), i - 1) * calcItem(x, 2 * i - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1.0;
  for (uint16_t i = 2; i < count + 1; i++) {
    sum += pown((-1.0), i - 1) * calcItem(x, 2 * i - 2);
  }
  return sum;
}
