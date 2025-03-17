// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double base, uint16_t exponent) {
  if (exponent == 0) {
    return 1.0;
  }
  double result = 1.0;
  for (uint16_t i = 1; i <= exponent; ++i) {
    result *= base;
  }
  return result;
}

uint64_t fact(uint16_t number) {
  if (number <= 1) {
    return 1ULL;
  }
  uint64_t total = 1ULL;
  for (uint16_t i = 2; i <= number; ++i) {
    total *= i;
  }
  return total;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    double sign = (i % 2 == 0) ? 1.0 : -1.0; 
    uint16_t power = 2 * i + 1;
    sum += sign * calcItem(x, power);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    double sign = (i % 2 == 0) ? 1.0 : -1.0; 
    uint16_t power = 2 * i;
    sum += sign * calcItem(x, power);
  }
  return sum;
}


