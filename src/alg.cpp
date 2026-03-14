// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double num = 1.0;
  for (uint64_t i = 0; i < n; i++) {
    num = num*value;
  }
  return num;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double num = 0.0;
  for (uint64_t i = 0; i <= count; i++) {
        num += calcItem(x, i);
    }
  return num;
}

double sinn(double x, uint16_t count) {
  double num = 0.0;
  for (uint64_t i = 0; i < count; i++) {
    if (i%2 == 0) {
      num += calcItem(x, (2*i-1));
    } else {
      num -= calcItem(x, (2*i-1));
    }
  }
  return num;
}

double cosn(double x, uint16_t count) {
  double num = 0.0;
  for (uint64_t i = 0; i < count; i++) {
    if (i%2 == 0) {
      num += calcItem(x, (2*i));
    } else {
      num -= calcItem(x, (2*i));
    }
  }
  return num;
}
