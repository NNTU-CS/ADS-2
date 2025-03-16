// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (uint16_t i = 0; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (uint16_t i = 1; i <= count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = x;  
  for (int k = 1; k < count; k++) {
    res += calcItem(x, 2 * k + 1) * pown(-1, k % 2);
  }
  return res; 
}

double cosn(double x, uint16_t count) {
  double res = 1;
  for (int k = 1; k < count; k++) {
    res += calcItem(x, 2 * k) * pown(-1, k % 2);
  }
  return res;
}
