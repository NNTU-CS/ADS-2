// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  uint16_t count = 1;
  double k = 1;
  while (count <= n) {
    k = k * value;
    count++;
  }
  return k;
}

uint64_t fact(uint16_t n) {
  uint64_t t = 1;
  while (n > 0) {
    t = t * n;
    n--;
  }
  return t;
}

double calcItem(double x, uint16_t n) {
  uint16_t count = 1;
  double k = 1;
  while (count <= n) {
    k = k * x;
    count++;
  }
  uint64_t t = 1;
  while (n > 0) {
    t = t * n;
    n--;
  }
  return (k / t);
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (uint16_t i = 1; i <= count; i++) {
    e = e + calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double si = 0;
  for (uint16_t i = 1; i <= count; i++) {
    uint16_t k = (i * 2) - 1;
    si = si + ((pown(-1, i - 1)) * calcItem(x, k));
  }
  return si;
}

double cosn(double x, uint16_t count) {
  double si = 0;
  for (uint16_t i = 1; i <= count; i++) {
    uint16_t k = (i * 2) - 2;
    si = si + ((pown(-1, i - 1)) * calcItem(x, k));
  }
  return si;
}
