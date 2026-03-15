// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double rez = 1.0;
  for (uint16_t i = 0; i < n; i++){
      rez = rez * value;
    }
  return rez;
}

uint64_t fact(uint16_t n) {
  uint64_t rez = 1;
  for (uint64_t i = 1; i <= n; i++) {
    rez = rez * i;
  }
  return rez;
}

double calcItem(double x, uint16_t n) {
  double a = pown(x,n);
  double b = fact(n);
  return a / b;
}

double expn(double x, uint16_t count) {
  double rez = 0;
  for (uint16_t i = 0; i < count; i++){
    rez = rez + (pown(x,i)/fact(i));
  }
  return rez;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; n++){
    uint16_t pow = 2 * n + 1;
    double a = calcItem(x,pow);
    if (n % 2 == 0){
      sum += a;
    } else {
      sum -= a;
    }
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; n++){
    uint16_t pow = 2*n;
    double a = calcItem(x,pow);
    if (n % 2 == 0){
      sum += a;
    } else {
      sum -= a;
    }
  }
  return sum;
}
