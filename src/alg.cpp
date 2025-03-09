// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double step = value;
  value = 1;
  for (int i = 0; i < n; ++i) {
    value *= step;
  }
  return value;
}

uint64_t fact(uint16_t n) {
  uint64_t value = 1;
  for (int i = 1; i < (n+1); ++i) {
    value *= i;
  }
  return value;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 1;
  for (int i = 1; i < count; ++i) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = x;
  for (int i = 2; i < count+1; ++i) {
    sum += pown(-1, i - 1) * pown(x, 2 * i - 1) / fact(2 * i - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1;
  for (int i = 2; i < count+1; ++i) {
    sum += pown(-1, i - 1) * pown(x, 2 * i - 2) / fact(2 * i - 2);
  }
  return sum;
}
