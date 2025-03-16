// Copyright 2022 NNTU-CS
#include <math.h>
#include <stdio.h>

#include <iostream>
#include <cstdint>

double pown(double value, uint16_t n) {
  double itog = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    itog *= value;
  }
  return itog;
}

uint64_t fact(uint16_t n) {
  uint64_t itog = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    itog *= i;
  }
  return itog;
}

double calcItem(double x, uint16_t n) {
  return (pow(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double itog = 1.0;
  for (uint16_t n = 1; n <= count; ++n) {
    itog += pow(x, n) / fact(n);
  }
  return itog;
}

double sinn(double x, uint16_t count) {
  if (x == 0.0) {
    return 0.0;
  }
  double itog = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    itog += pow(-1, n) * pow(x, 2 * n + 1) / fact(2 * n + 1);
  }
  return itog;
}

double cosn(double x, uint16_t count) {
  
  if (count == 0) {
    return 1.0;
  }
  double itog = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    itog += (n % 2 == 0 ? 1 : -1) * pow(x, 2 * n) / fact(2 * n);
  }
  return itog;
}
