// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double first, double current, uint16_t n) {
  if (n == 1) return current;
  else if (n == 0) return 1;
  return pown(first, current * first, n - 1);
}

double pown(double value, uint16_t n) {
  return pown(value, value, n);
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  if (count == 0) return 1;
  return calcItem(x, count) + expn(x, count - 1);
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  int8_t t;
  for (uint16_t n = 1; n <= count; n++) {
    if ((n - 1) % 2 == 0) t = 1;
    else t = -1;

    sum += t * calcItem(x, 2 * n - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  int8_t t;
  for (uint16_t n = 1; n <= count; n++) {
    if ((n - 1) % 2 == 0) t = 1;
    else t = -1;

    sum += t * calcItem(x, 2 * n - 2);
  }
  return sum;
}
