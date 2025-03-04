// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdint>
#include <cmath>

// Возведение value в степень n
double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

// Вычисление факториала n (n!) с обработкой переполнения
uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) return 1;
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
        if (result > UINT64_MAX / i) return UINT64_MAX; // Проверка на переполнение
        result *= i;
    }
    return result;
}

// Вычисление n-го члена ряда для exp(x)
double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

// Вычисление e^x
double expn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}

// Вычисление sin(x)
double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        sum += pow(-1.0, i) * pown(x, 2 * i + 1) / fact(2 * i + 1);
    }
    return sum;
}

// Вычисление cos(x)
double cosn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        sum += pow(-1.0, i) * pown(x, 2 * i) / fact(2 * i);
    }
    return sum;
}

