// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1.0;
  for (int i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  double result = 0;
  double p = 0;
  double f = 0;
  p = pown(x, n);
  f = fact(n);
  result = p / f;
  return result;
}

double expn(double x, uint16_t count) {
  double sum1 = 1;
  for (uint16_t i = 1; i <= count; i++) {
    sum1 += calcItem(x, i);
  }
  return sum1;
}

double sinn(double x, uint16_t count) {
  double sum2 = x;
  for (uint64_t i = 2; i <= count; i++) {
    sum2 += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 1);
  }
  return sum2;
}

double cosn(double x, uint16_t count) {
  double sum3 = 1;
  for (uint64_t i = 2; i <= count; i++) {
    sum3 += pown((-1.0), i - 1) * calcItem(x, (2 * i) - 2);
  }
  return sum3;
}
