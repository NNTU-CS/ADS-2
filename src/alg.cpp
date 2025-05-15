// Copyright 2022 NNTU-CS
#include <cstdint>
double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; ++i) {
    result *= value;
  }
  return result;
}
double fact(uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}
double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}
double expn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    result += calcItem(x, i);
  }
  return result;
}
double sinn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    uint16_t power = 2 * i + 1;
    double term = calcItem(x, power);
    if (i % 2 == 0) result += term;
    else result -= term;
  }
  return result;
}
double cosn(double x, uint16_t count) {
  double result = 0.0;
  for (uint16_t i = 0; i < count; ++i) {
    uint16_t power = 2 * i;
    double term = calcItem(x, power);
    if (i % 2 == 0) result += term;
    else result -= term;
  }
  return result;
}
