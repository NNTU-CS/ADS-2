// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>

double pown(double value, unsigned short n) {
  double result = 1.0;
    for (unsigned short i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(unsigned short n) {
  if (n == 0) return 1;
  uint64_t result = 1;
    for (unsigned short i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, unsigned short n) {
  return pown(x, n) / (double)fact(n);
}

double expn(double x, unsigned short count) {
  double result = 0.0;
    for (unsigned short i = 0; i <= count; ++i) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, unsigned short count) {
  double result = 0.0;
    for (unsigned short i = 0; i < count; ++i) {
        double term = ((i % 2 == 0) ? 1.0 : -1.0) * pown(x, 2 * i + 1) / (double)fact(static_cast<unsigned short>(2 * i + 1));
        result += term;
    }
    return result;
}

double cosn(double x, unsigned short count) {
  double result = 0.0;
    for (unsigned short i = 0; i < count; ++i) {
        double term = ((i % 2 == 0) ? 1.0 : -1.0) * pown(x, 2 * i) / (double)fact(static_cast<unsigned short>(2 * i));
        result += term;
    }
    return result;
}
