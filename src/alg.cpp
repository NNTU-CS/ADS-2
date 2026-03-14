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
    if (n == 0 || n == 1) { // Исправлено условие
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

    double sum = 0.0;

    for (uint16_t n = 0; n < max_terms; ++n) {
        sum += calcItem(x, n);
    }

    return sum;
}

double sinn(double x, uint16_t count) {
    x = std::fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;

    double sum = 0.0;

    for (uint16_t n = 0; n < count; ++n) {
        uint16_t power = 2 * n + 1;
        double sign = (n % 2 == 0) ? 1.0 : -1.0;
        double term = sign * pown(x, power);
        term /= static_cast<double>(fact(power));
        sum += term;
    }

    return sum;
}

double cosn(double x, uint16_t count) {
    x = std::fmod(x, 2 * M_PI);
    if (x > M_PI) x -= 2 * M_PI;
    if (x < -M_PI) x += 2 * M_PI;

    double sum = 0.0;

    for (uint16_t n = 0; n < count; ++n) {
        uint16_t power = 2 * n;
        double sign = (n % 2 == 0) ? 1.0 : -1.0;
        double term = sign * pown(x, power);
        term /= static_cast<double>(fact(power));
        sum += term;
    }

    return sum;
}


