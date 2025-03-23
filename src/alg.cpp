// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  while (n != 0){
    res *= value;
    n--;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t fact = 1ж
  for (uint16_t i = 1; i <= n; i++){
    fact *= i;
  }
  return fact;
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
