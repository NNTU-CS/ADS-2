// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  while (n) {
    n--;
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint32_t res = 1;
  if (n >= 1) {
    while (n) {
      res *= n;
      n--;
    }
    return res;
  }
  return 0;
}

double calcItem(double x, uint16_t n) {
  double res = 0;
  res = (pown(x, n) / fact(n));
  return res;
}

double expn(double x, uint16_t count) {
  double res = 1;
  while (count) {
    res += calcItem(x, count);
    count--;
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  int i = 1;
  while (i <= count) {
    if (i % 2 != 0) {
      res += calcItem(x, (2 * i - 1));
      i++;
    } else {
      res -= calcItem(x, (2 * i - 1));
      i++;
    }
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 1;
  int i = 2;
  while (i <= count) {
    if (i % 2 != 0) {
      res += calcItem(x, (2 * i - 2));
      i++;
    } else {
      res -= calcItem(x, (2 * i - 2));
      i++;
    }
  }
  return res;
}
