// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"



double pown(double value, uint16_t n) {
  long double OVal = 1;
  for (uint16_t i = 0; i < n; i++) {
    OVal *= value;
  }
  return OVal;
}

uint64_t fact(uint16_t n) {
  int64_t Result = 1;
  for (uint16_t i = 1; i <= n; i++) {
    Result *= i;
  }
  return Result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double Result = 0;
  for (uint16_t i = 0; i <= count; i++) {
    Result += pown(x, i) / fact(i);
  }
  return Result;
}

double sinn(double x, uint16_t count) {
  double Result = 0;
  double tmp = x;

  for (uint16_t i = 0; i <= count; i++) {
    Result += tmp;
    tmp *= -x * x / ((2 * i + 2) * (2 * i + 3));
  }

  return Result;
}

double cosn(double x, uint16_t count) {
  long double Result = 0;
  long double tmp = 1;

  for (uint16_t i = 0; i <= count; i++) {
    Result += tmp;
    tmp *= -x * x / ((2 * i + 1) * (2 * i + 2));
  }

  return (double)Result;
}
