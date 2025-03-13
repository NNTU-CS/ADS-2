// Copyright 2022 NNTU-CS

#include <iostream>
#include <cstdint>
#include <cmath>
#include "alg.h"

// Функция возведения value в степень n
constexpr double pown(double value, uint16_t n) {
    double result = 1.0;
    while (n--) {
        result *= value;
    }
    return result;
}

// Вычисление факториала n (n!) с обработкой переполнения
constexpr uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        if (result > UINT64_MAX / i) return UINT64_MAX;
        result *= i;
    }
    return result;
}

// Вычисление n-го члена ряда для exp(x)
constexpr double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

// Вычисление e^x через сумму ряда
constexpr double expn(double x, uint16_t count) {
    double sum = 1.0;
    double term = 1.0;
    for (uint16_t i = 1; i < count; ++i) {
        term *= x / i;
        sum += term;
    }
    return sum;
}

// Вычисление sin(x)
constexpr double sinn(double x, uint16_t count) {
    double sum = x;
    double term = x;
    for (uint16_t i = 1; i < count; ++i) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

// Вычисление cos(x)
constexpr double cosn(double x, uint16_t count) {
    double sum = 1.0;
    double term = 1.0;
    for (uint16_t i = 1; i < count; ++i) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}
