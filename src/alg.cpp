// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result = result * value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) return 1;
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
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
    double sum = 1.0;  // Начинаем с n=0 (значение 1)
    for (uint16_t n = 1; n <= count; n++) {
        sum = sum + calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        double sign = (n % 2 == 0) ? 1.0 : -1.0;
        uint16_t power = 2 * n + 1;
        double term = sign * calcItem(x, power);
        sum = sum + term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        double sign = (n % 2 == 0) ? 1.0 : -1.0;
        uint16_t power = 2 * n;
        double term = sign * calcItem(x, power);
        sum = sum + term;
    }
    return sum;
}
