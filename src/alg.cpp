// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (value == 0) {
      return 1;
  }  
  for (int i = 1; i<n ; i++){
    value *= value;
  }
  return value;
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
      return 1;
  }
  else {
      return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(x));
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (int i = 1; i <= count; i++){
      e += calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double s = x;
  for (int i = 1; i < count; i++){
      s += calcItem(x, 2 * i + 1)* pown(-1, i % 2);
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double c = 1;
  for (int i = 1; i < count; i++){
      c += calcItem(x, 2 * i) * pown(-1, i % 2);
  }
  return c;
}
