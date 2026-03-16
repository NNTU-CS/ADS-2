// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result = result * value;
    }
    return result;
}
uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}
double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}
double expn(double x, int n) {
    double sum = 1.0;  // первый член ряда (i=0)
    double term = 1.0;
    
    for (int i = 1; i < n; i++) {  // начинаем с i=1, т.к. i=0 уже учтен
        term *= x / i;  // рекуррентное соотношение: term = term * x / i
        sum += term;
    }
    
    return sum;
}

double sinn(double x, uint16_t count) {
    if (count == 0) {
        return 0.0;
    }
    double result = x;
    double term = x;
    for (uint16_t n = 1; n <= count - 1; ++n) {
        term = term * (-1.0) * x * x;
        term = term / static_cast<double>((2 * n) * (2 * n + 1));
        result = result + term;
    }
    return result;
}
double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; n++) {
    // Члены ряда cos(x): (-1)^n * x^(2n) / (2n)!
    double term = pown(-1.0, n) * pown(x, 2 * n) / fact(2 * n);
    sum += term;
  }
  return sum;
}
