// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = value;
  int count = n-1;
  while (count > 0) {
    count--;
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  int count = n - 1;
  uint64_t result = n;
  while (count > 0) {
    result *= count;
    count--;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double result = 0;
  result = pown(x, n) / fact(n);
  return result;
}

double expn(double x, uint16_t count) {
  int cnt = count;
  double result = 0;
  while (cnt > 0) {
    result += calcItem(x, cnt);
      cnt--;
  }
  return ++result;
}

double sinn(double x, uint16_t count) {
  int cnt = 2;
  double result = 0;
  int sign = 0;
  while (cnt <= count) {
    sign = pown((-1), (cnt));
    result += (sign * calcItem(x, ((2 * cnt) - 1)));
    cnt++;
  }
  return (x - result);
}

double cosn(double x, uint16_t count) {
  int cnt = 2;
  double result = 0;
  int sign = 0;
  while (cnt <= count) {
    sign = pown((-1), (cnt));
    result += (sign * calcItem(x, ((2 * cnt) - 2)));
    cnt++;
  }
  return (1 - result);
}
