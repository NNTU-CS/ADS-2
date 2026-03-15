// Copyright 2022 NNTU-CS

#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;

    for (uint16_t i = 0; i < n; i++) {
        result = result * value;
    }

    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;

    for (uint16_t i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

double calcItem(double x, uint16_t n) {
    double power = pown(x, n);
    uint64_t factorial = fact(n);

    return power / factorial;
}

double expn(double x, uint16_t count) {
    double sum = 0.0;

    for (uint16_t n = 0; n <= count; n++) {
        double term = calcItem(x, n);
        sum = sum + term;
    }

    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;

    for (uint16_t n = 0; n < count; n++) {

        double sign = pown(-1.0, n);
        double power = pown(x, 2 * n + 1);
        uint64_t factorial = fact(2 * n + 1);

        double term = sign * power / factorial;

        sum = sum + term;
    }

    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;

    for (uint16_t n = 0; n < count; n++) {

        double sign = pown(-1.0, n);
        double power = pown(x, 2 * n);
        uint64_t factorial = fact(2 * n);

        double term = sign * power / factorial;

        sum = sum + term;
    }

    return sum;
}
