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
    // Ограничиваем количество членов (макс. 21 для избежания переполнения fact)
    uint16_t max_terms = (count > 21) ? 21 : count;

    double sum = 1.0;  // Первый член ряда: x^0 / 0! = 1
    double current_term = 1.0; // Текущий член ряда

    // Суммируем члены от n=1 до n=max_terms-1
    for (uint16_t n = 1; n < max_terms; ++n) {
        // Рекуррентное соотношение: term(n) = term(n-1) * x / n
        current_term *= x / n;
        sum += current_term;
    }

    return sum;
}

double sinn(double x, uint16_t count) {
    x = std::fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;

    double sum = x;  // Первый член: x^1 / 1! = x
    double current_term = x;

    for (uint16_t n = 1; n < count; ++n) {
        // Рекуррентное соотношение для sin: term(n) = -term(n-1) * x^2 / ((2n)(2n+1))
        double x_squared = x * x;
        double numerator = -x_squared;
        uint16_t term1 = 2 * n;
        uint16_t term2 = 2 * n + 1;
        double denominator = static_cast<double>(term1 * term2);
        double factor = numerator / denominator;
        current_term *= factor;
        sum += current_term;
    }

    return sum;
}

double cosn(double x, uint16_t count) {
    x = std::fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;

    double sum = 1.0;  // Первый член: x^0 / 0! = 1
    double current_term = 1.0;

    for (uint16_t n = 1; n < count; ++n) {
        // Рекуррентное соотношение для cos: term(n) = -term(n-1) * x^2 / ((2n-1)(2n))
        double x_squared = x * x;
        double numerator = -x_squared;
        uint16_t factor1 = 2 * n - 1;
        uint16_t factor2 = 2 * n;
        double denominator = static_cast<double>(factor1 * factor2);
        double factor = numerator / denominator;
        current_term *= factor;
        sum += current_term;
    }

    return sum;
}
