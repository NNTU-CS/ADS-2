// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return 1;
  }
  else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  if (count == 0) {
    return 1.0;
  }
  return expn(x, count - 1) + calcItem(x, count);
}

double sinn(double x, uint16_t count) {
  if (count == 0) {
    return x;
  }
  return sinn(x, count - 1) + pown(-1, 2 * count -1) * calcItem(x, 2 * count - 1);
}

double cosn(double x, uint16_t count) {
  if (count == 0) {
    return 1;
  }
  return sinn(x, count - 1) + pown(-1, count - 1) * calcItem(x, 2 * count - 2);
}
