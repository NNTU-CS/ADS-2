// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"



double pown(double value, uint16_t n) {
  if (n == 1)
    return value;
  else
    return pown(value, n - 1) * value;
}

uint64_t fact(uint16_t n) {
  uint64_t fac = 1;
  for (uint64_t i = 1; i <= n; i++) {
    fac *= i;
  }
  return fac;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 0; i <= count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 1; i <= count; i++) {
    if (i % 2 == 0)
      sum -= calcItem(x, 2 * i - 1);
    else
      sum += calcItem(x, 2 * i - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1;
  for (uint16_t i = 2; i <= count; i++) {
    if (i % 2 == 0)
      sum -= calcItem(x, 2 * i - 2);
    else
      sum += calcItem(x, 2 * i - 2);
  }
  return sum;
}

