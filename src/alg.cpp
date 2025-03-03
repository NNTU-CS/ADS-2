// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double j = value;
  if (n == 0)
    return 1;
  for (uint16_t i = 1; i < n ; ++i)
    j *= value;
  return j;
}

uint64_t fact(uint16_t n) {
  if (n == 0)
    return 1;
  uint64_t j = 1;
  for (uint64_t i = 1; i <= n ; ++i)
  j *= i;
  return j;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n)/fact(n);
}

double expn(double x, uint16_t count) {
  double j = 0;
  for (uint16_t i = 0; i <= count ; i++)
  j+=calcItem(x, i);
  return j;
}

double sinn(double x, uint16_t count) {
  double j = 0;
  for (uint16_t i = 0; i < count; i++)
    j += ((i % 2 == 0) ? 1.0 : -1.0) * calcItem(x, 2 * i + 1);
  return j;
}

double cosn(double x, uint16_t count) {
  double j = 0;
  for (uint16_t i = 0; i < count; i++)
    j += ((i % 2 == 0) ? 1.0 : -1.0) * calcItem(x, 2 * i);
  return j;
}
