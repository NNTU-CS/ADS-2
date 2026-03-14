// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double k = value;
    if (n == 0) {
      return 1;
    } else {
      for (uint64_t i = 1; i < n; i++) {
        k *= value;
    }
  }
  return k;
}

uint64_t fact(uint16_t n) {
  uint16_t k = n;
  uint64_t facti = 1;
  if (n <= 1) {
    return 1;
  } else {
    for (uint64_t i = 0; i < n; i++) {
      facti *= k;
      k -= 1;
    }
  }
  return facti;
}

double calcItem(double x, uint16_t n) {
  double k = pown(x, n) / fact(n);
  return k;
}

double expn(double x, uint16_t count) {
  double e = 1;
  uint64_t n = 1;
  for (uint64_t i = 0; i < count; i++) {
    e += pown(x, n) / fact(n);
    n += 1;
  }
  return e;
}
double sinn(double x, uint16_t count) {
  double e = 0;
  uint64_t n = 1;
  for (uint64_t i = 0; i < count; i++) {
    if (i % 2 == 0)
      e += pown(x, n) / fact(n);
    else
      e -= pown(x, n) / fact(n);
    n += 2;
  }
  return e;
}

double cosn(double x, uint16_t count) {
  double e = 0;
  uint64_t n = 0;
  for (uint64_t i = 0; i < count; i++) {
    if (i % 2 == 0)
        e += pown(x, n) / fact(n);
    else
        e -= pown(x, n) / fact(n);
    n += 2;
  }
  return e;
}
