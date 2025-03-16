// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) return 1;
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
  double result =1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= x;
  }
  for (uint16_t i = 1; i <= n; ++i) {
    result /= i;
  }
  return result;
}

double expn(double x, uint16_t count) {
  double summ = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        summ += calcItem(x, n);
    }
    return summ;
}

double sinn(double x, uint16_t count) {
  double summ = 0.0;
  double c = x;
  int sym = 1;
  for (uint16_t n = 0; n <= count; ++n) {
    summ += sym * c;
    c *= x * x / ((2 * n) * (2 * n + 1));
    sym = -sym;
  }
  return summ;
}

double cosn(double x, uint16_t count) {
  double summ = 0.0;
  double c = 1.0;
  int sym = 1;
  for (uint16_t n = 0; n <= count; ++n) {
    summ += sym * c;
    c *= x * x / ((2 * n - 1) * (2 * n));
    sym = -sym;
  }
  return summ;
}
