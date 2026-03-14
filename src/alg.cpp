// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <cmath>

double pown(double value, uint16_t n) {
  return std::pow(value, n);
}

uint64_t fact(uint16_t n) {
  if (n == 1 || n == 0) {
    return 1;
  }
  uint64_t result = 1;
  for (uint64_t i = 2; i <= n; i++) {
    result*=i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double chislitel = pown(x, n);
  double znamenatel = fact(n);
  return chislitel / znamenatel;
}

double expn(double x, uint16_t count) {
  double sum = 1;
  if (count == 0) {
    return 0;
  }
  if (count == 1) {
    return 1;
  }
  for (int n = 1; n <= count; n++) {
    sum += pown(x, n) / fact(n);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (int i = 1; i <= count; ++i) {
    double chislitel = pown(x, 2*i-1);
    double znamenatel = fact(2*i-1);
    double sign = (i % 2 == 0) ? -1.0 : 1.0;
    sum += sign * (chislitel / znamenatel);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1.0;
  if (count == 1) {
    return 1;
  }
  for (int i = 2; i <= count; ++i) {
    double chislitel = pown(x, 2*i-2);
    double znamenatel = fact(2*i-2);
    double sign = (i % 2 == 0) ? -1.0 : 1.0;
    sum += sign * (chislitel / znamenatel);
  }
  return sum;
}
