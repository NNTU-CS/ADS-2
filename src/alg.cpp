#include <cstdint>
#include <cmath>

namespace {
int8_t getSign(uint16_t n) {
    return (n % 2 == 0) ? 1 : -1;
}

} 


double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}


uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}


double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        result += calcItem(x, n);
    }
    return result;
}


double sinn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        // Член ряда: (-1)^n * x^(2n+1) / (2n+1)!
        double term = pown(x, 2*n + 1) / static_cast<double>(fact(2*n + 1));
        result += getSign(n) * term;
    }
    return result;
}


double cosn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t n = 0; n < count; ++n) {
        // Член ряда: (-1)^n * x^(2n) / (2n)!
        double term = pown(x, 2*n) / static_cast<double>(fact(2*n));
        result += getSign(n) * term;
    }
    return result;
}
