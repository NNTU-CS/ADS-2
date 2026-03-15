// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (uint64_t i = 0; i < n; i++) res *= value;
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t a = 1;
  for (uint64_t i = 1; i <= n; i++) a *= i;
  return a;
}

double calcItem(double x, uint16_t n) {
  double m = 1.;
  for (uint64_t i = 1; i <= n; i++) m *= i;
  for (uint64_t i = 0; i, n; i++) x *= x;
  return (x/m);
}

double expn(double x, uint16_t count) {
  double sum = 0.;
    for (uint16_t i = 0; i < count; i++) {
      sum += pown(x, i) / fact(i);
      count++;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.;
    for (uint16_t n = 1; n <= count; n++) {
        uint16_t k = 2 * n - 1;
        double t = pown(x, k) / fact(k);
        if (n % 2 == 0) t = -t;
        sum += t;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.;
    for (uint16_t n = 1; n <= count; n++) {
        uint16_t k = 2 * n - 2;
        double t = pown(x, k) / fact(k);
        if (n % 2 == 0) t = -t;
        sum += t;
    }
    return sum;
}
