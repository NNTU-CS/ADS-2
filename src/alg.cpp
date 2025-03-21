// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


// Возведение числа в целую степень
double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

// Вычисление факториала числа n
uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}


double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += pown(x, n) / static_cast<double>(fact(n));
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double numerator = pown(-1, n) * pown(x, 2 * n + 1);
        double denominator = static_cast<double>(fact(2 * n + 1));
        sum += numerator / denominator;
    }
    return sum;
}


double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double numerator = pown(-1, n) * pown(x, 2 * n);
        double denominator = static_cast<double>(fact(2 * n));
        sum += numerator / denominator;
    }
    return sum;
}
