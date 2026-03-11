// Copyright 2022 NNTU-CS

#include "alg.h"

#include <cstdint>


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  }

  if (n == 1) {
    return value;
  }

  return value * pown(value, n - 1);
}


uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }

  if (n == 1) {
    return n;
  }

  return n * fact(n - 1);
}


double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}


double expn(double x, uint16_t count) {
  if (count == 0) {
    return 1.0;
  }

  return expn(x, count - 1) + calcItem(x, count);
}


double sinn(double x, uint16_t count) {
  if (count == 0) {
    return 0.0;
  }

  uint16_t n = 2 * count - 1;
  double term = calcItem(x, n);

  if ((count - 1) % 2 == 1) {
    term = -term;
  }

  return sinn(x, count - 1) + term;
}


double cosn(double x, uint16_t count) {
  double sum = 1.0;
  double term = 1.0;

  for (uint16_t i = 1; i <= count; i++) {
    term *= -x * x / ((2 * i - 1) * (2 * i));
    sum += term;
  }

  return sum;
}
