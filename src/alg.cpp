// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
      return 1;
    } else {
      double k = value;
      for (uint64_t i = 1; i < n; i++) {
        value *= k;
    }
  }
  return value;
}

uint64_t fact(uint16_t n) {
  uint64_t facti = 1;
  if (n <= 1) {
    return 1;
  } else {
    for (uint64_t i = 1; i <= n; i++) {
      facti *= i;
    }
  }
  return facti;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n <= count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t k = 0; k < count; ++k) {
        double term = pown(x, 2 * k + 1) / static_cast<double>(fact(2 * k + 1));
        if (k % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t k = 0; k < count; ++k) {
        double term = pown(x, 2 * k) / static_cast<double>(fact(2 * k));
        if (k % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    return sum;
}
