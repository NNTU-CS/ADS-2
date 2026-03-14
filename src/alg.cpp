// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double res = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
   uint64_t res = 1;
    for (uint16_t i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 0.0;
    for (uint16_t n = 0; n <= count; n++) {
        res += calcItem(x, n);
    }
    return res;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        uint16_t power = 2 * n - 1;
        double term = calcItem(x, power);
        bool isNegative = (n % 2 == 0);
        if (isNegative) {
            res -= term;
        } 
				else {
            res += term;
        }
    }
    return res;
}

double cosn(double x, uint16_t count) {
  double res = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        uint16_t power = 2 * n - 2;
        double term = calcItem(x, power);
        bool isNegative = (n % 2 == 0);
        if (isNegative) {
            res -= term;
        } 
				else {
            res += term;
        }
    }
    return res;
}
