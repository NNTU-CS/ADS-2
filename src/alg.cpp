// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) return 1;
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    double item = 1.0;  // первый член при n=0: x^0/0! = 1
    for (uint16_t n = 0; n < count; n++) {
        if (n == 0) {
            result += 1.0;
        } else {
            item *= x / n;  // рекуррентная формула: следующий член = предыдущий * x/n
            result += item;
        }
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    double item = x;  // первый член: x
    for (uint16_t n = 1; n <= count; n++) {
        if (n == 1) {
            result += x;
            item = x;  // сохраняем для следующей итерации
        } else {
            // рекуррентная формула: следующий член = - предыдущий * x^2 / ((2n-2)*(2n-1))
            item *= -x * x / ((2*n - 2) * (2*n - 1));
            result += item;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    double item = 1.0;  // первый член: 1
    for (uint16_t n = 0; n < count; n++) {
        if (n == 0) {
            result += 1.0;
            item = 1.0;  // сохраняем для следующей итерации
        } else {
            // рекуррентная формула: следующий член = - предыдущий * x^2 / ((2n-1)*(2n))
            item *= -x * x / ((2*n - 1) * (2*n));
            result += item;
        }
    }
    return result;
}
