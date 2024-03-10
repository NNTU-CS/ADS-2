// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double k = value;
  if (n == 1) {
    return value;
  }
  if (n == 0) {
    return 1;
  }
  for (uint32_t i = 2; ++i) {
    value *= k;
    if (n == i) {
      return value;
    }
  }
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  if (n == 0) {
    return 1;
  }
  for (uint32_t i = 1; i <= n; ++i) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (uint32_t i = 0; i <= count; ++i) {
    sum += calcItem(i, x);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
   double sum = 0;
  for (uint32_t i = 1; i <= count; ++i) {
    double pow = 1;
    if ((i - 1) % 2 != 0) {
      pow = -1;
    }
    sum += pow * calcItem(2 * i - 1, x);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
   double sum = 0;
  for (uint32_t i = 1; i <= count; ++i) {
    double pow = 1;
    if ((i - 1) % 2 != 0) {
      pow = -1;
    }
    sum += pow * calcItem(2 * i - 2, x);
  }
  return sum;
}
