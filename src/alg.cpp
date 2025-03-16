// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdint>
#include <cmath>
#include "alg.h"

double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (uint16_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double sum = 1.0; // Начинаем с первого члена ряда (n=0)
  double term = 1.0; // Это будет n! для n=0

  for (uint16_t n = 1; n < count; ++n) {
    term *= x / n; // Вычисляем следующий член ряда
    sum += term;   // Добавляем к сумме
  }
  
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n + 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t n = 0; n < count; ++n) {
    sum += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n);
  }
  return sum;
}
