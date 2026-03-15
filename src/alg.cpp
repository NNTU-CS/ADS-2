// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
      res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (uint16_t i = 2; i <= n; ++i) {
      res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    double term = 1.0; 
    for (uint16_t n = 0; n <= count; ++n) {
        if (n == 0) {
            term = 1.0;
        } else {
            term *= x / static_cast<double>(n);
        }
        sum += term;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; i++) {
      double p = pown(x, 2 * i + 1) / fact(2 * i + 1);
      if (i % 2 == 0) {
          sum += p;
      } else {
          sum -= p;
      }
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double summ = 0.0;
  for (uint16_t i = 0; i < count; i++) {
      double p = pown(x, 2 * i) / fact(2 * i);
      if (i % 2 == 0) {
          summ += p;
      } else {
        summ -= p;
      }
  }
  return summ;
}
