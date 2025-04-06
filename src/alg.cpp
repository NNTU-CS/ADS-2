// Copyright 2022 NNTU-CS
#include <cstdint>

double pown(double value, uint16_t n) {
    double result = 1.0;
    int i = 0;
    while (i < n) {
        result *= value;
        ++i;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    while (n > 1) {
        result *= n--;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    double numerator = pown(x, n);
    double denominator = fact(n);
    double res = numerator / denominator;
    return res;
}

double expn(double x, uint16_t count) {
    double summation = 1.0;
    for (uint16_t i = 1; i <= count; ++i) {
        summation += calcItem(x, i);
    }
    return summation;
}

double sinn(double x, uint16_t count) {
    double summation = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        double term = calcItem(x, 2 * i + 1);
        summation += (i % 2 == 0) ? term : -term;
    }
    return summation;
}

double cosn(double x, uint16_t count) {
    double summation = 1;
    for (int i = 2; i <= count; ++i) {
        summation += pown(-1, i-1) * calcItem(x, 2 * i - 2);
    }
    return summation;
}
