// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1.0;
  }
  double res = value;
  for (int i = 1; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  for (int i = 1; i < n; i++) {
    n *= i;
  }
  return n;
}

double calcItem(double x, uint16_t n) {
  double num = pown(x, n) / fact(n);
  return num;
}

double expn(double x, uint16_t count) {
  double res = 1.0;
  for (int i = 1; i < count; i++) {
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = x;
  for (int i = 2; i < count; i++) {
    res += pown(-1, i-1) * calcItem(x, 2 * i - 1);
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 1;
  for (int i = 2; i < count; i++) {
    res += pown(-1, i-1) * calcItem(x, 2 * i - 2);
  return res;
}
