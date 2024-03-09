// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double result = value;
  if (n == 0) {
    return 1;
  } else {
  for (int i = 1; i < n; i++) {
    result *= value;
  }
  return result;
}
}

uint64_t fact(uint16_t n) {
  if (n <= 1)
    return 1;
  else
    return (n* fact(n - 1));
}

double calcItem(double x, uint16_t n) {
return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
  double result = 1;
  for (int n = 1; n <= count; n++) {
    result += calcItem(x, n);
  }
  return result;
}

double sinn(double x, uint16_t count)  {
  double result = x, k = 1;
  for (int n = 2; n <= count; n++) {
    result += (pown(-1.0, n-1) * calcItem(x, 2*n-1));
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 1, k = 1;
  for (int n = 2; n <= count; n++) {
    result += (pown(-1.0, n-1) * calcItem(x, 2*n-2));
  }
  return result;
}
