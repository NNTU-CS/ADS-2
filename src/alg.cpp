// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double result = 1;
  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1)
        return 1;

    uint64_t result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;

    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t i = 0; i <= count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    int sign = 1;
    for (uint16_t n = 1; n <= count; n++) {
        sum += sign * calcItem(x, 2 * n - 1);
        sign = -sign;
    }

    return sum;
}

double cosn(double x, uint16_t count) {
  double res = 0;
  for (uint16_t i = 1; i <= count; i++) {
    res += pown(-1, i - 1) * calcItem(x, (2 * (i - 1)));
  }
  return res;
}
