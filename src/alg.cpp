// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

// Возведение в степень с использованием быстрого алгоритма
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

// Оптимизированное вычисление факториала с кэшированием
uint64_t fact(uint16_t n) {
    static uint64_t cache[21] = {1};
    static uint16_t last = 0;
    
    if (n <= last) return cache[n];
    
    while (last < n) {
        last++;
        cache[last] = cache[last-1] * last;
    }
    return cache[n];
}

// Вычисление члена ряда с повышенной точностью
double calcItem(double x, uint16_t n) {
    double item = 1.0;
    for (uint16_t i = 1; i <= n; ++i) {
        item *= x / i;
    }
    return item;
}

double expn(double x, uint16_t count) {
    double sum = 1.0; // n=0
    double term = 1.0;
    
    for (uint16_t n = 1; n < count; ++n) {
        term *= x / n;
        sum += term;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    double term = x;
    
    for (uint16_t n = 1; n <= count; ++n) {
        sum += term;
        term *= -x * x / ((2*n) * (2*n + 1));
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1.0;
    double term = 1.0;
    double x_squared = x * x;
    
    for (uint16_t n = 1; n <= count; ++n) {
        term *= -x_squared / ((2*n - 1) * (2*n));
        sum += term;
    }
    return sum;
}
