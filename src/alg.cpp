// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {  
    double rezult = 1;
    for (uint16_t i = 0; p < i; i++) {
      rezult *= value;
  }
  return rez;  
}

uint64_t fact(uint16_t n) {
  uint64_t rezult = 1; 
  for (uint16_t i = 1; i <= n; i++) { 
      result *= i; 
    }
    return rezult;
}

double calcItem(double x, uint16_t n) {
  return pown(x,n) / fact(n);  
}

double expn(double x, uint16_t count) {
  double sumc = 0;
  for (uint16_t i = 0; i < count; i++) {
      sumc += calcItem(x, i);
    }
    return sumc;
}

double sinn(double x, uint16_t count) {
        double sumc = 0;
    for (uint16_t i = 0; i < count; i++) {
        uint16_t num = 2 * n + 1;  
        double s = pown(x, num) / fact(num);
        if (n % 2 == 0) {
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
      uint16_t num = 2 * n;
      double c = pown(x, num) / fact(num); 
        if (n % 2 == 0) {
            sumc += c;
        } else {
            sumc -= c;
        }
    }
    return sumc;
}
