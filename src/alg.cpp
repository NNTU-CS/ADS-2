// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double result = 1;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0) return 1;
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++)
        result *= i;
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double sum = 0;
    for (uint16_t i = 0; i <= count; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}
double sinn(double x, uint16_t count) {
    double sum = 0;
    int iter = 1;
    for (uint16_t i = 0; i < count; i++) {
        if (i % 2 == 0)
            sum += calcItem(x, iter);
        else sum -= calcItem(x, iter);
        iter += 2;
    }
    return sum;
}
double cosn(double x, uint16_t count) {
    double res = 0;
    int iter = 0;
    for (uint16_t j = 0; j < count; j++) {
        if (j % 2 == 0) res += calcItem(x, iter);
        else res -= calcItem(x, iter);
        iter += 2;
    }
    return res;
}
