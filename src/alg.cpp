// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    double res = value;
    for (uint16_t i = n; i > 1; i--) {
      res *= value;
    }
    return res;
  }
}

uint64_t factF(uint64_t n, uint64_t res) {
  if (n == 0)
    return res;
  else
    return factF(n - 1, res * n);
}
uint64_t fact(uint16_t n) {
  return factF(n, 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double exp(double x, uint16_t count, double res) {
  if (count == 0)
    return res + calcItem(x, count);
  else
    return exp(x, count - 1, res + calcItem(x, count));
}
double expn(double x, uint16_t count) {
  return exp(x, count, 0);
}

double sin(double x, uint16_t count, double res) {
  if (count == 1)
    return res + calcItem(x, count);
  else
    return sin(x, count - 1,
      (res + pown(-1, count - 1) * calcItem(x, count * 2 - 1)));
}
double sinn(double x, uint16_t count) {
  return sin(x, count, 0);
}

double cos(double x, uint16_t count, double res) {
  if (count == 0)
    return res;
  else
    return cos(x, count - 1,
      (res + pown(-1, count - 1) * calcItem(x, count * 2 - 2)));
}
double cosn(double x, uint16_t count) {
  return cos(x, count, 0);
}
