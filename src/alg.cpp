// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <math.h>


double pown(double value, uint16_t n) {
  return pow(value, n);
}

uint64_t fact(uint16_t n) {
  uint64_t f = 1;
  for (uint16_t i = 1; i <= n; i++){
    f *= i;
  }
  return f;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
  double ex = 0;
  for (uint16_t i = 0; i <= count; i++){
    ex += calcItem(x, i);
  }
  return ex;
}

double sinn(double x, uint16_t count) {
  double sn = 0;
  int ch = -1;
  for (uint16_t i = 1; i <= count; i++){
    sn += (pown((ch), (i-1)))*(calcItem(x, 2*i-1))
  }
  return sn;
}

double cosn(double x, uint16_t count) {
  double cn = 0;
  int ch = -1;
  for (uint16_t i = 1; i <= count; i++){
    cn += (pown((ch), (i-1)))*(calcItem(x, 2*i-2))
  }
  return cn;
}
