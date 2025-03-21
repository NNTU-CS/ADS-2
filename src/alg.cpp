// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    double halfPower = pown(value, n / 2);
    if (n % 2 == 0) {
        return halfPower * halfPower;
    }
    else {
        return halfPower * halfPower * value;
    }
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) return 1;
    if (factorialCache.find(n) != factorialCache.end()) {
        return factorialCache[n];
    }
    factorialCache[n] = n * fact(n - 1);
    return factorialCache[n];
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  return sumSeries(x, count, [x](uint16_t n) { return calcItem(x, n); });
}

double sinn(double x, uint16_t count) {
  return sumSeries(x, count, [x](uint16_t n) {
    return pown(-1, n) * pown(x, 2 * n + 1) / fact(2 * n + 1);
  });
}

double cosn(double x, uint16_t count) {
  return sumSeries(x, count, [x](uint16_t n) {
    return pown(-1, n) * pown(x, 2 * n) / fact(2 * n);
  });
}
