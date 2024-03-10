// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double value1 = value;
  for (uint16_t i = 2; i <= n; ++i) {
    value *= value1;
  }
  return value;
}

uint64_t fact(uint16_t n) {
    if (n == 1) {
    return 1;
  } else {
    return fact(n-1) * n;
  }
}

double calcItem(double x, uint16_t n) {
return (pown(x, n)) / fact(n);
}

double expn(double x, uint16_t count) {
    double summ = 1;
    for (uint64_t i = 1; i <= count; i++) {
        summ += pown(x, i) / fact(i);
    }
    return summ;
}

double sinn(double x, uint16_t count) {
  double sin = 0;
  uint16_t m = 1;
  for (uint16_t i = 1; i <= count*2; i+=2) {
    if (m % 2 == 0) {
      sin -= calcItem(x, i);
  } else {
    sin += calcItem(x, i);
    }
m++;
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1;
  uint16_t m = 1;
  for (uint16_t i = 2; i < count*2; i += 2) {
    if (m % 2 != 0) {
      cos -= calcItem(x, i);
    } else {
      cos += calcItem(x, i);
    }
m++;
}
  return cos;
}
