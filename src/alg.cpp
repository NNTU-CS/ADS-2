// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

#include <stdint.h>

double pown(double value, uint16_t n) {
    double result = 1.0;
    while (n > 0) {
        result *= value;
        n--;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        sum += pown(x, n) / fact(n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        double term = pown(x, 2*n - 1) / fact(2*n - 1);
        sum += (n % 2 == 1) ? term : -term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        double term = pown(x, 2*(n - 1)) / fact(2*(n - 1));
        sum += (n % 2 == 1) ? term : -term;
    }
    return sum;
}
