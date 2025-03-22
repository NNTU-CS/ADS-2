// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double q = 1;
  for (uint16_t i = 1; i < n + 1; i++) {
    q = q * value;
  }
  return q;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t q = 1;
  for (uint16_t i = 1; i < n + 1; i++) {
    q *= i;
  }
  return q;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 1;
  for (uint16_t i = 1; i < count + 1; i++) {
    sum += pown(x, i) / fact(i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double s = x;
  for (uint16_t i = 2; i < count + 1; i++) {
    s += pown(-1, i - 1) * (pown(x, 2 * i - 1) / fact(2 * i - 1));
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double s = 1;
  for (uint16_t i = 2; i < count + 1; i++) {
    s += pown(-1, i + 1) * pown(x, 2 * i - 2) / fact(2 * i - 2);
  }
  return s;
}
