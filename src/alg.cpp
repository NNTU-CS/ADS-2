// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
  if (n == 0) {
       return 1.0;
   }
   double result = 1.0;
   while (n > 0) {
       if (n % 2 == 1) {
           result *= value;
       }
      value *= value;
       n /= 2;
  }
  return result;
}
uint64_t fact(uint16_t n) {
if (n == 0) return 1; // 0! = 1 
   uint64_t result = 1;
   for (uint16_t i = 1; i <= n; ++i) {
       if (result > std::numeric_limits<uint64_t>::max() / i) {
        return 0;
    }
    result *= i;
  }
  return result;
}
double calcItem(double x, uint16_t n) {
  double result = 1.0;
    for (uint16_t i = 1; i <= n; ++i) {
        result *= x / i;
    }
    return result;
}
double expn(double x, uint16_t count) {
  double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
  if (count == 0) return 0.0;
    double sum = x;
    double term = x;
    for (uint16_t n = 2; n <= count; ++n) {
        term *= -x * x / ((2 * n - 1) * (2 * n - 2));
        sum += term;
    }
    return sum;
}
double cosn(double x, uint16_t count) {
  if (count == 0) return 0.0;
    double sum = 1.0;
    double term = 1.0;
    for (uint16_t n = 2; n <= count; ++n) {
        term *= -x * x / ((2 * n - 2) * (2 * n - 3));
        sum += term;
    }
    return sum;
}
