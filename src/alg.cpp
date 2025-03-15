// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double result = 1.0;
  while (n--) {
    result *= value;
  } return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  } return result;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) return 1.0;
  return calcItem(x, n - 1) * x / n;
}

double expn(double x, uint16_t count) {
  double result = 0.0;
  double term = 1.0;
  result = term;
  for (uint16_t n = 1; n < count; ++n) {
    term *= x / n; 
    result += term; 
  } return result;
}

double sinn(double x, uint16_t count) {
  double sum = x;
  double term = x;
  for (uint16_t i = 1; i < count; ++i) {
    term *= -x * x / ((2 * i) * (2 * i + 1));
    sum += term;
  } return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1.0;
  double term = 1.0;
  for (uint16_t i = 1; i < count; ++i) {
    term *= -x * x / ((2 * i - 1) * (2 * i));
    sum += term;
  } return sum;
}
