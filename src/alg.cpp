// Copyright 2022 NNTU-CS
#include <cstdint>
#include <iostream>
#include <cmath>
#include "alg.h"


double pown(double value, uint16_t n) {
  double p = 1;
  for ( ; n > 0; --n )
    p *= value;
  return p;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
        result *= i;
    }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double sum = 2;
    for ( ; count > 1; count-- ) {
        sum += calcItem(x, count);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double result = x;
    for (uint16_t k = 2; k <= count; k++) {
        result += pown((-1.0), k - 1) * calcItem(x, (k * 2) - 1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 1.0;
    for (uint16_t k = 2; k <= count; k++) {
        result += pown((-1.0), k - 1) * calcItem(x, (k * 2) - 2);
    }
    return result;
}
