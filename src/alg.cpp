// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double sum = value;
  for (int i = 1; i < n; i++) {
    sum *= value;
  }
  return sum;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  for (int i = 1; i < n; i++) {
    n *= i;
  }
  return n;
}

double calcItem(double x, uint16_t n) {
  double num = pown(x, n) / fact(n);
  return num;
}

double expn(double x, uint16_t count) {
  return 0.0;
}

double sinn(double x, uint16_t count) {
  return 0.0;
}

double cosn(double x, uint16_t count) {
  return 0.0;
}
