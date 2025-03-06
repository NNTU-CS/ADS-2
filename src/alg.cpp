// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"



double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double result = 1.0;
  while (n > 0) {
    if (n % 2 == 1) result *= value;
    value *= value; 
    n /= 2; 
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  uint64_t result = 1;
  for (uint64_t i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = x; 
  double per_ch = x; 
  for (uint16_t i = 2; i < count+1; i++) {
    per_ch *= -x * x / ((2 * i) * (2 * i + 1)); 
    sum += per_ch; 
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1.0; 
  double per_ch = 1.0; 
  for (uint16_t i = 1; i < count; i++) {
    per_ch *= -x * x / ((2 * i - 1) * (2 * i)); 
    sum += per_ch; 
  }
  return sum;
}
