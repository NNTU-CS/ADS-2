// Copyright 2022 NNTU-CS
#include <iostream>
#include <cmath>
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  return std::pow(value, n);
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (int i = 0; i < count; ++i) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (int i = 0; i < count; ++i) {
    sum += std::pow(-1, i) * calcItem(x, 2 * i + 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (int i = 0; i < count; ++i) {
    sum += std::pow(-1, i) * calcItem(x, 2 * i);
  }
  return sum;
}
