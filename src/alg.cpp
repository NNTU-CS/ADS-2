// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include "math.h"
#include <cmath>

double pown(double value, uint16_t n) {
 if (n == 0) {
  return 1.0;
 }
 double res = 1.0;
 for (uint16_t i = 0; i < n; ++i) {
  res *= value;
 }
 return res;
}

uint64_t fact(uint16_t n) {
 uint64_t factorial = 1;
 for (uint16_t i = 1; i <= n; ++i) {
  factorial *= i;
 }
 return factorial;
}

double calcItem(double x, uint16_t n) {
 const double PI = acos(-1.0);
 double item = 0.0;
 item = pow(x, n) / fact(n);
 return item;
}

double expn(double x, uint16_t count) {
 double e = 0.0;
 for (uint16_t n = 0; n < count; ++n) {
  e += (pow(x, n) / fact(n));
 }
 return e;
}

double sinn(double x, uint16_t count) {
 double sin = 0.0;
 const double PI = acos(-1.0);
 for (uint16_t n = 0; n < count; ++n) {
  sin += pow(-1, n) * pow(x, 2 * n + 1) / fact(2 * n + 1);
 }
 return sin;
}

double cosn(double x, uint16_t count) {
 double cos = 0.0;
 const double PI = acos(-1.0);
 for (uint16_t n = 0; n < count; ++n) {
  cos += pow(-1, n) * pow(x, 2 * n) / fact(2 * n);
 }
 return cos;
}
