// Copyright 2022 NNTU-CS
#include <cmath>
#include <iostream>
#include <cstdint>


uint16_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fact(n-1) * n;
}

double pown(double value, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= value;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return (pown(x, n)) / (fact(n));
}

double expn(double x, uint16_t count) {
    double result = 1;
    double term = 1;
    for (int i = 1; i <= count; i++) {
        term *= x/i;
        result += term;
    }
    return result;
}

double sinn(double x, uint16_t count) {
    if (x == 0) return 0;
    double result = 0;
    int sign = 1;
    for (int i = 1; i <= count; i++) {
        result += sign * (pow(x, (2*i - 1)) / fact(2*i - 1));
        sign *= -1;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double res = 0;
    for (int i = 1; i <= count; i++) {
        res += pown(-1, i-1) * (pown(x, (2*i - 2)) / fact((2*i - 2)));
    }
    return res;
}
