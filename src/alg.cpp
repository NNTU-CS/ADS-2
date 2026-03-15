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
  if (n == 1)
    return 1;
  else
    return n*fact(n-1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact (n);
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 0; i <= count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t i = 1; i <= count; i++) {
      double pown1 = pown((-1), (i-1));
      double pown2 = pown(x, (2*i-1));
      uint64_t fact1 = fact(2*i-1);
      sum += pown1 * (pown2 / fact1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double summ = 0;
  for (uint16_t i = 1; i <= count; i++) {
      double pown1 = pown((-1), (i-1));
      double pown2 = pown(x, (2*i-2));
      uint64_t fact1 = fact(2*i-2);
      summ += pown1 * (pown2 / fact1);
  }
  return summ;
}
