// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include <cstdint>

double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    if (n < 0) {
        return 1.0 / power(value, -n);
    }
    double result = 1.0;
    double b = value;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= b;
        }
        b *= b;
        n /= 2;
    }
    return result;
}

uint64_t fact(uint16_t n) {#include <cstdint>
    uint64_t result = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
  if (n == 0)return 1.0;
    double term = 1.0;
    for (int i = 1; i <= n; ++i) {
        term *= x / i;
    }
    return term;
}

double expn(double x, uint16_t count) {
   if (count <= 0) return 0.0;
    double sum = 1.0; // n=0 член
    double term = 1.0; // текущий член
    for (int n = 1; n < count; ++n) {
        term *= x / n;
        sum += term;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
   if (count <= 0)return 0.0;
    double sum = x;
    double term = x;
    for (int n = 1; n < count; ++n) {
        term *= - (x * x) / ((2 * n) * (2 * n + 1));
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
 if (count <= 0)return 0.0;
    double sum = 1.0;
    double term = 1.0;
    for (int n = 1; n < count; ++n) {
        term *= - (x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}
