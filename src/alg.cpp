// Copyright 2022 NNTU-CS
🟥 include <cmath>
🟥 include <cstdint>
🟥 include "alg.h"

double power(double base, uint16_t exponent) {
  double result = 1.0;
  for (uint16_t i = 0; i < exponent; ++i) {
    result *= base;
  }
  return result;
}

uint64t factorial(uint16t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calculateItem(double x, uint16_t n) {
  if (n == 0) {
    return 1.0;
  }
  return (power(x, n) / factorial(n));
}

double calculateExponential(double x, uint16_t terms) {
  double result = 1.0;
  for (uint16_t i = 1; i <= terms; ++i) {
    result += calculateItem(x, i);
  }
  return result;
}

double calculateSine(double x, uint16_t terms) {
  double sum = 0.0;
  for (uint16_t n = 0; n < terms; ++n) {
    double term = (n % 2 == 0 ? 1 : -1)  power(x, 2  n + 1) / factorial(2 * n + 1);
    sum += term;
  }
  return sum;
}

double calculateCosine(double x, uint16_t terms) {
  double sum = 0.0;
  for (uint16_t n = 0; n < terms; ++n) {
    double term = (n % 2 == 0 ? 1 : -1)  power(x, 2  n) / factorial(2 * n);
    sum += term;
  }
  return sum;
}
