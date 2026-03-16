// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}
uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) return 1;
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}
double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        sum += pown(x, n) / fact(n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        if (n % 2 == 1) {
            sum += pown(x, 2*n-1) / fact(2*n-1);
        } else {
            sum -= pown(x, 2*n-1) / fact(2*n-1);
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1.0;
    for (uint16_t n = 2; n <= count; n+=2) {
        if ((n/2) % 2 == 1) {
            sum -= pown(x, n) / fact(n);
        } else {
            sum += pown(x, n) / fact(n);
        }
    }
    return sum;
}
