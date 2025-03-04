// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
  return 1.0;
  }
  double result = 1.0;
  for (int i = 0; i < n; i++) {
  result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
  return 1.0;
  }
  double result = 1.0;
  for (int i = 2; i <= n; i++) {
  result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
  double a = 1;
  for (int i = 1; i < count+1; i++) {
  a += pown(x, i) / fact(i);
  }
  return a;
}

double sinn(double x, uint16_t count) {
  double a = 0;
  for (uint16_t i = 0; i < count; i++)
    a += ((i % 2 == 0) ? 1.0 : -1.0) * calcItem(x, 2 * i + 1);
  return a;
}

double cosn(double x, uint16_t count) {
  double a = 0;
  for (uint16_t i = 0; i < count; i++)
    a += ((i % 2 == 0) ? 1.0 : -1.0) * calcItem(x, 2 * i);
  return a;
}
