// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double rez = 1;
  for (uint16_t p = 0; p < n; p++) {
    rez *= value;
  }
  return rez;
}

uint64_t fact(uint16_t n) {
  uint64_t rez = 1;
  for (uint16_t p = 2; p <= n; p++) {
    rez *= p;
  }
  return rez;
}

double calcItem(double x, uint16_t n) {
  double chis = pown(x, n);
  uint64_t znam = fact(n);
  return chis / znam;
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t p = 0; p < count; p++) {
    double a = calcItem(x, p);
    sum += a;
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t p = 0; p < count; p++) {
    uint16_t step = p * 2 + 1;
    double chis = pown(x, step);
    uint64_t znam = fact(step);
    double a = chis / znam;
    if (p % 2 == 0) {       
      sum += a;
    } else {
      sum -= a;
    }
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0;
  for (uint16_t p = 0; p < count; p++) {
    uint16_t step = p * 2;
    double chis = pown(x, step);
    uint64_t znam = fact(step);
    double a = chis / znam;
    if (p % 2 == 0) {         
      sum += a;      
    } else {
      sum -= a;
    }
  }
  return sum;
}
