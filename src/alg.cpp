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
  unsigned long long Result = 1;
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
  for (uint16_t i = 0; i < count; i++){
    Result += pown(x, i) / fact(count);
  }
  return Result;
}

double sinn(double x, uint16_t count) {
  double Result = 0;
  for (uint16_t i = 0; i < count; i++){
    Result += pown(-1, count - 1) * (pown(x, 2 * count - 1) / fact(2 * count - 1));
  }
  return Result;
}

double cosn(double x, uint16_t count) {
  double Result = 0;
  for (uint16_t i = 0; i < count; i++){
    Result += pown(-1, count - 1) * (pown(x, 2 * count - 2) / fact(2 * count - 2));
  }
  return Result;
}
