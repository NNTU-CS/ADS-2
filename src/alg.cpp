// Copyright 2022 NNTU-CS
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdint>

uint64_t fact(uint16_t n) {
    if (n > 20) {
        std::cerr << "Error: n too large for factorial "
                  << "(max 20), n = " << n << std::endl;
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double pown(double base, uint16_t exp) {
    if (exp == 0) return 1.0;
    double result = 1.0;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 0.0;

    // Увеличиваем количество членов для большей точности
    uint16_t max_n = (count > 20) ? 20 : count;

    for (uint16_t n = 0; n <= max_n; ++n) {
        sum += calcItem(x, n);
    }

    return sum;
}
