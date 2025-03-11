// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, int n) {
  double rez = 1.0;
  for (int i = 0; i < n; ++i) {
    rez *= value;
  }
  return rez;
}

uint64_t fact(uint16_t n) {
  uint64_t rez = 1;
  for (size_t i = 2; i <= n; ++i) {
    rez *= i;
  }
  return rez;
}

double calc_item(double x, uint16_t n) {
  long double rez = pown(x, n) / fact(n);
  return rez;
}

double expn(double x, uint16_t count) {
  long double rez = 1.0L;
  for (size_t i = 1; i <= count; ++i) {
    rez += pown(x, i) / fact(i);
  }
  return rez;
}

double sinn(double x, uint16_t count) {
  double rez = 0.0;
  for (size_t i = 1; i <= count; ++i) {
    if (i % 2 == 0) {
      rez -= pown(x, 2 * i - 1) / fact(2 * i - 1);
    } else {
      rez += pown(x, 2 * i - 1) / fact(2 * i - 1);
    }
  }
  return rez;
}

double cosn(double x, uint16_t count) {
  double rez = 0.0;
  for (size_t i = 1; i <= count; ++i) {
    if (i % 2 == 0) {
      rez -= pown(x, 2 * i - 2) / fact(2 * i - 2);
    } else {
      rez += pown(x, 2 * i - 2) / fact(2 * i - 2);
    }
  }
  return rez;
}
