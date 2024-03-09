#include <iostream>
#include <cmath>

double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    double result = value;
    for (uint16_t i = 1; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    uint64_t result = 1;
    for (uint16_t i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        result += pown(-1, i) * calcItem(x, 2*i+1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        result += pown(-1, i) * calcItem(x, 2*i);
    }
    return result;
}

int main() {
    double x = 1.0;
    uint16_t count = 10;
    std::cout << "exp " << x << " is " << expn(x, n) << std::endl;
    std::cout << "sin " << x << " is " << sinn(x, count) << std::endl;
    std::cout << "cos " << x << " is " << cosn(x, count) << std::endl;
    
    return 0;
}
