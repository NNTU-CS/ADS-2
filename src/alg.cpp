// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    if (n % 2 == 0) {
        return pown(x, n) / static_cast<double>(fact(n));
    } else {
        return pown(x, n) / static_cast<double>(fact(n));
    }
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
        sum += (n % 2 == 0 ? -1 : 1) * calcItem(x, 2 * n + 1);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n);
    }
    return sum;
}
