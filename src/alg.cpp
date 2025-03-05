// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = value;
  for (int i = 1; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  int mult = 1;
  if (n == 1) {
    return 1;
  }
  for (int i = 2; i <= n; i++) {
    mult *= i;
  }
  return mult;
}

double calcItem(double x, uint16_t n) {
  double up = 0, down = 0;
  up = pown(x, n);
  down = fact(n);
  return up / down;
}

double expn(double x, uint16_t count) {
  double sum = 1;
  for (int n = 1; n < count; n++) {
    sum += calcItem(x, n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  return 0.0;
}

double cosn(double x, uint16_t count) {
  return 0.0;
}
