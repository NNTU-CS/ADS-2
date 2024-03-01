// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

int sumOrMinus(int n) {
  return (n - 1) % 2 == 0 ? 1 : -1;
}

double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double copy = value;
  for (uint16_t i = 0; i < n - 1; i++) {
    value *= copy;
  }
  return value;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (int i = n; i > 0; i--) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 1;
  for (uint16_t i = 1; i <= count; i++) {
    result += pown(x, i) / fact(i);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t i = 1; i <= count; i++) {
    result += sumOrMinus(i) * (pown(x, 2 * i - 1) / fact(2 * i - 1));
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0;
  for (int i = 1; i <= count; i++) {
    result += sumOrMinus(i) * (pown(x, 2 * i - 2) / fact(2 * i - 2));
  }
  return result;
}
