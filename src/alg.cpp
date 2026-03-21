// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
  for (uint16_t i = 1; i <= n; i++) {
    res = res * value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t f = 1;
  for (uint16_t i = 2; i <= n; i++) {
    f = f * i;
  }
  return f;
}

double calcItem(double x, uint16_t n) {
  double ch = pown(x, n);
  uint64_t zn = fact(n);
  return ch / zn;
}

double expn(double x, uint16_t count) {
  double s = 0.0;
  for (uint16_t i = 0; i <= count; i++) {
    s = s + calcItem(x, i);
  }
  return s;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    double znak;
    if (i % 2 == 0) {
      znak = 1.0;
    } else {
      znak = -1.0;
    }
    int st = 2 * i + 1;
    double sl = znak * pown(x, st) / fact(st);
    res = res + sl;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double otvet = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    double sign;
    if (i % 2 == 0) {
      sign = 1.0;
    } else {
      sign = -1.0;
    }
    int step = 2 * i;
    double member = sign * pown(x, step) / fact(step);
    otvet = otvet + member;
  }
  return otvet;
}
