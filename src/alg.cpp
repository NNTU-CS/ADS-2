// Copyright 2022 NNTU-CS
#include <cstdint>
#include <iostream>
#include "alg.h"

using namespace std;

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n, char choice) {
    switch (choice) { 
    case 'e':
        return pown(x, n) / fact(n);
    case 's':
        return pown(-1.0, n - 1) * (pown(x, (2 * n) - 1) / fact((2 * n) - 1));
    case 'c':
        return pown(-1.0, n - 1) * (pown(x, (2 * n) - 2) / fact((2 * n) - 2));
    default:
        cout << "Неверный выбор. Попробуйте снова" << endl;
        return 0.0;  
    }
}

double expn(double x, uint16_t count) {
    double sum = 1.0;  
    for (uint16_t i = 1; i < count; i++) {
        sum += calcItem(x, i, 'e');
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = x;  
    for (uint16_t i = 2; i < count; i++) {  
        sum += calcItem(x, i, 's');
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1.0;  
    for (uint16_t i = 1; i < count; i++) {  
        sum += calcItem(x, i, 'c');
    }
    return sum;
}
