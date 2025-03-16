// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"


double pown(double value, uint16_t n) {
  return std::pow(value, n);
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return powN(x, n) / static_cast<double>(factorial(n));
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += calculateItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  int sign = 1;
  for (uint16_t n = 1; n <= count; n += 2) {
    sum += sign * calculateItem(x, n);
    sign = -sign;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  int sign = 1;
  for (uint16_t n = 0; n <= count; n += 2) { 
    sum += sign * calculateItem(x, n);
    sign = -sign; 
  }
  return sum;
}
