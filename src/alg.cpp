// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0)
    return 1;
  double res = 1;
  for (uint16_t i = 1; i <= n; i++) {
    res *= value;
  }

  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0)
    return 1;
  uint64_t res = 1;

  for (int i = 1; i <= n; i++) {
    res *= i;
  }

  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t i = 0; i <= count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  int pow_i = 1;
  for (uint16_t j = 0; j < count; j++) {
    if (j % 2 == 0)
      res += calcItem(x, pow_i);
    else
      res -= calcItem(x, pow_i);
    pow_i += 2;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0;
  int pow_i = 0;
  for (uint16_t j = 0; j < count; j++) {
    if (j % 2 == 0)
      res += calcItem(x, pow_i);
    else
      res -= calcItem(x, pow_i);
    pow_i += 2;
  }
  return res;
}
