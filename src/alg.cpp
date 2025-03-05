// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  double numerator = pown(x, n);
  double demominator = fact(n);
  double res = numerator / demominator;
  return res;
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (int i = 1; i < count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = x - calcItem(x, 3);
  double sign = -1.0;
  if (count == 0) return 0;
  if (count == 1) return x;
  if (count == 2) return x - (calcItem(x, 3));
  for (int i = 5; i <= count; i += 2) {
    res += sign * calcItem(x, i);
    sign *= -1.0;
  } 
  return res;
}

double cosn(double x, uint16_t count) {
  if (count == 0) return 1;
  if (count == 2) return 1 - calcItem(x, 2);
  double res = 1 - calcItem(x, 2);
  double sign = -1.0;
  for (int i = 4; i <= count; i += 2) {
    res += sign * calcItem(x, i);
    sign *= -1.0;
  }
  return res;
}
