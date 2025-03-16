// Copyright 2025 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= value;
        }
        value *= value;
        n /= 2;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1); // Рекурсивная реализация факториала
}

double calcItem(double x, uint16_t n) {
    if (n == 0) {
        return 1.0; // Первый член ряда экспоненты всегда 1
    }

    double numerator = pown(x, n);
    double denominator = fact(n);

    if (n % 2 == 1) {
        // Нечетное n: синус
        return pown(-1, (n - 1) / 2) * (numerator / denominator);
    } else {
        // Четное n: косинус или экспонента
        return numerator / denominator;
    }
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n); // Все члены ряда для экспоненты
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, 2 * n + 1); // Только нечетные n
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, 2 * n); // Только четные n
    }
    return sum;
}
