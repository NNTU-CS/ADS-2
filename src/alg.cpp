// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t a = 1; a <= n; ++i) {
    result *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  while (n > 1) {
    result *= n--;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double num = pown(x, n);
  uint64_t dem = fact(n);
  return num / static_cast<double>(dem);
}

double expn(double x, uint16_t count) {
  double total = 0.0;
  for (uint16_t idx = 0; idx <= count; ++idx) {
    total += calcItem(x, idx);
  }
  return total;
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  uint16_t i = 0;
  while (i < count) {
    double signa = (i % 2 == 0) ? 1.0 : -1.0;
    uint16_t expon = 2 * i + 1;
    double num = pown(x, expon);
    uint64_t dem = fact(expon);
    result += sign * num / static_cast<double>(dem);
    ++i;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double accumu = 0.0;
  for (uint16_t ter = 0; ter < count; ++ter) {
    double signa = (ter % 2 == 0) ? 1.0 : -1.0;
    uint16_t power = 2 * ter;
    double numer = pown(x, power);
    uint64_t denom = fact(power);
    accumulator += signa * numer / static_cast<double>(denom);
  }
  return accumur;
}
