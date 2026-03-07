// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  return n == 0 ? 1.0 : value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
  if (n <= 1) return 1;
  uint64_t result = n * fact(n - 1);
  return result;
}

double calcItem(double x, uint16_t n) {
  return n == 0 ? 1.0 : pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  return count == 0 ? calcItem(x, 0) : expn(x, count - 1) + calcItem(x, count);
}

double sinn(double x, uint16_t count) {
  if (count == 0) return 0;
  uint16_t n = count;
  return sinn(x, count - 1) + (pown(-1, n - 1) * calcItem(x, 2 * n - 1));
}

double cosn(double x, uint16_t count) {
  if (count == 0) return 0;
  uint16_t n = count;
  return cosn(x, count - 1) + (pown(-1, n - 1) * calcItem(x, 2 * n - 2));
}
