// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double result = 1.0;
  while (n--) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  return 0.0;
}

double calcItem(double x, uint16_t n) {
  return 0.0;
}

double expn(double x, uint16_t count) {
  return 0.0;
}

double sinn(double x, uint16_t count) {
  return 0.0;
}

double cosn(double x, uint16_t count) {
  return 0.0;
}
