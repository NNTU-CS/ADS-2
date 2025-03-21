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

// Вычисление члена ряда для exp(x), sin(x), cos(x)
double calcItem(double x, uint16_t n) {
    // Для exp(x): x^n / n!
    // Для sin(x): (-1)^n * x^(2n+1) / (2n+1)!
    // Для cos(x): (-1)^n * x^(2n) / (2n)!
    // В этой функции мы вычисляем член ряда для exp(x), так как это общий случай.
    return pown(x, n) / static_cast<double>(fact(n));
}

// Вычисление exp(x) с суммированием count членов ряда
double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

// Вычисление sin(x) с суммированием count членов ряда
double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = pown(-1, n) * pown(x, 2 * n + 1) / static_cast<double>(fact(2 * n + 1));
        sum += term;
    }
    return sum;
}

// Вычисление cos(x) с суммированием count членов ряда
double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        double term = pown(-1, n) * pown(x, 2 * n) / static_cast<double>(fact(2 * n));
        sum += term;
    }
    return sum;
}
