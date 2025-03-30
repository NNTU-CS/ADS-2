// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;

  for (uint16_t i = 0; i < n; i++) {
    result *= value;
  }

  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;

  for (uint16_t i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) {
    return 1.0;
  }

  static double prev_item = 1.0;
  prev_item *= x / n;

  return prev_item;
}

double expn(double x, uint16_t count) {
  double sum = 0.0;
  double current_item = 1.0;

  for (uint16_t n = 0; n < count; n++) {
    sum += current_item;
    if (n < count - 1) {
      current_item *= x / (n + 1);
    }
  }

  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  double current_term = x;

  for (uint16_t k = 0; k < count; k++) {
    sum += (k % 2 == 0) ? current_term : -current_term;
    if (k < count - 1) {
      current_term *= x * x / ((2*k + 2) * (2*k + 3));
    }
  }

  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  double current_term = 1.0;

  for (uint16_t k = 0; k < count; k++) {
    sum += (k % 2 == 0) ? current_term : -current_term;
    if (k < count - 1) {
      current_term *= x * x / ((2*k + 1) * (2*k + 2));
    }
  }

  return sum;
}
