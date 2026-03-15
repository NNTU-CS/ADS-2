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
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n <= count; ++n) {
    sum += calcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  if (count == 0) return 0.0;
  double sum = x;
  double current = x;
  for (uint16_t i = 1; i < count; ++i) {
    double chisl = -x * x;
    double znam = (2.0 * i) * (2.0 * i + 1);
    current *= chisl / znam;
    sum += current;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  if (count == 0) return 0.0;
  double sum = 1.0;
  double current = 1.0;
  for (uint16_t i = 1; i < count; ++i) {
    double chisl = -x * x;
    double znam = (2.0 * i - 1) * (2.0 * i);
    current *= chisl / znam;
    sum += current;
  }
  return sum;
}
