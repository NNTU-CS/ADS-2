// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double a = 1.0;
    for (uint64_t i=0; i < n; i++) {
        a = a*value;
    }
    return a;
}

uint64_t fact(uint16_t n) {
  uint64_t ed = 1;
  for (uint64_t i = 1; i <= n; i++) {
      ed = ed*i;
  }
  return ed;
}

double calcItem(double x, uint16_t n) {
return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
double a = 0;
    for (uint64_t i=0; i <= count; i++) {
        a = a+(pown(x, i) / fact(i));
    }
    return a;
}

double sinn(double x, uint16_t count) {
    double ed = x;
    for (uint16_t i=2; i <= count; i++) {
        ed = ed+pown((-1.0), i-1) * calcItem(x, (2 * i)-1);
    }
    return ed;
}

double cosn(double x, uint16_t count) {
    double ed = 1.0;
    for (uint16_t i=2; i <= count; i++) {
        ed = ed+pown((-1.0), i-1) * calcItem(x, (i * 2)-2);
    }
    return ed;
}
