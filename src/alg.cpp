#include <cstdint>
#include <cmath>
#include "alg.h"
double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    return value * pow(value, n - 1);
  }
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}
double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}
double expn(double x, uint16_t count) {
  double res = 0;
  for (int i = 0; i <= count; i++) {
    res += calcItem(x, i);
  }
  return res;
}
double sinn(double x, uint16_t count) {
  double res = 0;
  for (int i = 1; i <= count; i++) {
    res += pow(-1, i - 1) * calcItem(x, 2 * i - 1);
  }
  return res;
}
double cosn(double x, uint16_t count) {
  double res = 0;
  for (int i = 1; i <= count; i++) {
    res += pow(-1, i - 1) * calcItem(x, 2 * i - 2);
  }
  return res;
}
