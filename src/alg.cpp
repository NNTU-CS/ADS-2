#include <cstdint>
#include "alg.h"

double pow(double value, uint16_t n) {
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
    return pow(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        result += calcItem(x, n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 1; n <= count; n++) {
        double item = pow(x, 2*n - 1) / static_cast<double>(fact(2*n - 1));
        if (n % 2 == 1) {  // нечет n дают +
            result += item;
        } else {  // чет n дают -
            result -= item;
        }
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; n++) {
        double item = pow(x, 2*n) / static_cast<double>(fact(2*n));
        if (n % 2 == 0) {  // чет n дают +
            result += item;
        } else {  // нечет n дают -
            result -= item;
        }
    }
    return result;
}
