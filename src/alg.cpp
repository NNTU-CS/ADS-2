#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double rezult = 1;
    for (uint16_t i = 0; i < n; i++) {
      rezult *= value;
  }
  return rezult;
}

uint64_t fact(uint16_t n) {
  uint64_t rezult = 1;
  for (uint16_t i = 1; i <= n; i++) {
      rezult *= i;
    }
    return rezult;
}

double calcItem(double x, uint16_t n) {
  return pown(x,n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sumc = 0;
  for (uint16_t i = 0; i <= count; i++) {
      sumc += calcItem(x, i);
    }
    return sumc;
}

double sinn(double x, uint16_t count) {
    double sumc = 0;
    for (uint16_t i = 0; i < count; i++) {
        uint16_t num = 2 * i + 1;
        double s = pown(x, num) / fact(num);
        if (i % 2 == 0) {
            sumc += s;
        } else {
            sumc -= s;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
  double sumc = 0;
  for (uint16_t i = 0; i < count; i++) {
      uint16_t num = 2 * i;
      double c = pown(x, num) / fact(num); 
        if (i % 2 == 0) {
            sumc += c;
        } else {
            sumc -= c;
        }
    }
    return sumc;
}
