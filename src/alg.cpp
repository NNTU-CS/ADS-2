// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  return pown(value, value, n);
}

double pown(double first, double current, uint16_t n) {
  if (n == 1) return current;
  else if (n == 0) return 1;
  return pown(first, current * first, n - 1);
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  if (count < 0) return 0;
  return calcItem(x, count) + expn(x, count - 1);
}

double sinn(double x, uint16_t count) {
  if (count < 0) return 0;
  return pown(-1, count - 1) * calcItem(x, 2 * count - 1) + sinn(x - 2, count - 2);
}

double cosn(double x, uint16_t count) {
  if (count < 0) return 0;
  return pown(-1, count - 1) * calcItem(x, 2 * count - 2) + cosn(x - 2, count - 2);
}
