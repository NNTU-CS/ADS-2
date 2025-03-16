// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double number = 1;
  for (int i = 1; i <= n; i++) {
    number *= value;
  }
  return number;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  uint64_t fac = 1;
  for (uint16_t i = n; i >1; i--) {
    fac *= i;
  }
  return fac;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double exp = 1;
  for (int i = 1; i <= count; i++) {
    exp += calcItem(x, i);
  }
  return exp;
}

double sinn(double x, uint16_t count) {
  double sin = x;
  for (int i = 1; i < count; i++) {
    sin += calcItem(x, 2 * i + 1) * pown(-1, i % 2);
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1;
  for (int i = 1; i < count; i++) {
    cos += calcItem(x, 2 * i) * pown(-1, i % 2);
  }
  return cos;
}
