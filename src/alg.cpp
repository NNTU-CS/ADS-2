// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double sum = value;
    for (uint16_t i = 0; i < n; i++) {
        sum *= value;
    }
    return sum;
}

uint64_t fact(uint16_t n) {
    if (n == 0) return 1;
    uint64_t sum = n;
    for (uint64_t i = n-1; i > 0; i--) {
        sum *= i;
    }
    return sum;
}

double calcItem(double x, uint16_t n) {
    double numerator = pown(x, n);
    double denominator = fact(n);
    return numerator/denominator;
}

double expn(double x, uint16_t count) {
    double sum = 1.0;
    for (uint16_t i = 1; i < count + 1; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = x;
    for (uint16_t i = 2; i < count; i++) {
        sum += pown((-1.0), i - 1) * calcItem(x, 2 * i + 1);;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1.0;
    for (uint16_t i = 1; i < count; i++) {
        sum += pown((-1.0), i - 1) * calcItem(x, 2 * i);
    }
    return sum;
}
