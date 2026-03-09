// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>

double pown(double value, uint16_t n) {
  double result = value;
  for (int i = 0; i < n; i++) {
    result = result * result;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1, a = 1;
  for (int i = 0; i < n; i++) {
    result = result * a;
    a++;
  }
  return result;
}

double calcItem(double x, uint16_t n) { return (pown(x, n) / fact(n)); }

double expn(double x, uint16_t count) {
  double result;
  for (int i = 0; i <= count; i++) {
  }
  return 0.0;
}

double sinn(double x, uint16_t count) { return 0.0; }

double cosn(double x, uint16_t count) { return 0.0; }
