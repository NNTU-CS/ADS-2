// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 0)
    return 1;
  double result = 1;
  for (uint16_t counter = 1; counter <= n; counter++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0)
    return 1;
  uint64_t result = 1;
  for (int counter = 1; counter <= n; counter++) {
    result *= counter;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double result = 0;
  for (uint16_t counter = 0; counter <= count; counter++) {
    result += calcItem(x, counter);
  }
  return result;
}

double sinn(double x, uint16_t count) {
  double result = 0;
  int power = 1;
  for (uint16_t counter = 0; counter < count; counter++) {
    if (counter % 2 == 0)
      result += calcItem(x, power);
    else
      result -= calcItem(x, power);
    power += 2;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0;
  int power = 0;
  for (uint16_t counter = 0; counter < count; counter++) {
    if (counter % 2 == 0)
      result += calcItem(x, power);
    else
      result -= calcItem(x, power);
    power += 2;
  }
  return result;
}
