//Copyright [2025] <Copyright Alexey Efimov>
#include <cstdint>
#include <iostream>
#include "alg.h"


double pown(double value, uint16_t n) {
  double x = value;
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return value;
    } else {
        for (int i = 2; i <= n; i++) {
            value *= x;
        }
        return value;
    }
}

uint64_t fact(uint16_t n) {
  int x = 1;
    for (int i = 1; i <= n; i++) {
        x *= i;
    }
    return x;
}

double calcItem(double x, uint16_t n) {
  if (n == 1) {
        return 1;
    } else {
        n = n - 1;
        return pown(x, n) / fact(n);
    }
}

double expn(double x, uint16_t count) {
  double res = 0;
    for (int i = 1; i <= count; i++) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
    for (int i = 1; i <= count; i++) {
        res += pown(-1, i - 1) * (pown(x, (2 * i - 1)) / fact(2 * i - 1));
    }
    return res;
}

double cosn(double x, uint16_t count) {
  double res = 0;
    for (int i = 1; i <= count; i++) {
        res += pown(-1, i - 1) * (pown(x, (2 * i - 2)) / fact((2 * i - 2)));
    }
    return res;
}
