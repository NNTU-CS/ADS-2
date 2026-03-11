// Copyright 2022 NNTU-CS

#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return value;
  }

  return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return n;
  }

  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  if (count == 0) {
    return 1.0;
  }

  return expn(x, count - 1) + calcItem(x, count);
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;

  for (uint16_t n = 0, i = 1; n < count; n++, i += 2) {
    sum += (pown(x, i) / static_cast<double>(fact(i))) * pown(-1, n);
  }

  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;

  for (uint16_t n = 0, i = 0; n < count; n++, i += 2) {
    sum += (pown(x, i) / static_cast<double>(fact(i))) * pown(-1, n);
  }

  return sum;
}
