// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  uint64_t res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) return 1.0;
  double numerator = pown(x, n);
  double demominator = fact(n);
  double res = numerator / demominator;
  return res;
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (int i = 1; i <= count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  if (count == 0) return 0;
  double res = 0;
  double sign = 1.0;
  for (uint16_t i = 1; i <= count; i++) {
    int I = 2 * i + 1;
    res += sign * calcItem(x, I);
    sign *= -1;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  if (count == 0) return 1;
  double res = 1;
  double sign = -1.0;
  for (uint16_t i = 2; i <= count; i++) {
    int I = 2 * i;
    res += sign * calcItem(x, I);
    sign *= -1;
  }
  return res;
}
