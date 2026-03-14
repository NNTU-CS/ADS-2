// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1;
  for (uint16_t counter = 0; counter < n; ++counter) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t factorial = 1;
  for (uint16_t mp = 2; mp <= n; ++mp) {
        factorial *= mp;
    }
  return factorial;
}

double calcItem(double x, uint16_t n) {
  double result = pown(x, n) / fact(n);
  return result;
}

double expn(double x, uint16_t count) {
  double expSum = 1;
  for (uint16_t step = 1; step <= count; ++step) {
      expSum += calcItem(x, step);
  }
  return expSum;
}

double sinn(double x, uint16_t count) {
  double sinSum = 0;
  for (uint16_t step = 1; step <= count; ++step) {
    sinSum += (pown(-1, step - 1) * calcItem(x, 2 * step - 1));
  }
  return sinSum;
}

double cosn(double x, uint16_t count) {
  double cosSum = 0;
  for (uint16_t step = 1; step <= count; ++step) {
    cosSum += (pown(-1, step - 1) * calcItem(x, 2 * step - 2));
  }
  return cosSum;
}
