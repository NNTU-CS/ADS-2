// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>


double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    double result = 1.0;

    for (int i = 1; i <= n; i++) {
        result *= x / i;
    }

    return result;
}

double expn(double x, uint16_t count) {
    double result = 0.0;

    for (int i = 0; i < count; i++) {
        result += pow (x, i) / tgamma(i+1);
    }

    return result;
}

double sinn(double x, uint16_t count) {
    double result = x;
    double term = x;

    for (uint16_t i = 1; i < count; i++) {
        term *= -x * x / ((2 * i + 1) * (2 * i));
        result += term;
    }

    return result;
}

double cosn(double x, uint16_t count) {
    double result = 1.0;
    double term = 1.0;

    for (uint16_t i = 1; i < count; i++) {
        term *= -x * x / ((2 * i) * (2 * i - 1));
        result += term;
    }

    return result;
}