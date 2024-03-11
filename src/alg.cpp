// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
double result = 1.0;
    for (uint64_t k = 0; k < n; k++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
uint64_t result = 1;
    for (uint64_t k = 1; k <= n; k++) {
        result *= k;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
double result = pown(x, n) / fact(n);
    return result;
}

double expn(double x, uint16_t count) {
double result = 1;
    for (uint16_t k = 1; k <= count; k++) {
        result += calcItem(x, k);
    }
    return result;
}

double sinn(double x, uint16_t count) {
double result = x;
    for (uint16_t k = 2; k <= count; k++) {
        result += pown((-1.0), k - 1) * calcItem(x, (k * 2) - 1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
double result = 1.0;
    for (uint16_t k = 2; k <= count; k++) {
        result += pown((-1.0), k - 1) * calcItem(x, (k * 2) - 2);
    }
    return result;
}
