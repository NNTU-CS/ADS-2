// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
#include <valarray>



double pown(double value, uint16_t n) {
    double rez = 1.0;
    for (uint16_t i = 0; i < n; i++) {
        rez *= value;
    }
    return rez;
}

uint64_t fact(uint16_t n) {
    uint64_t rez = 1;
    for (uint16_t i = 2; i <= n; i++) {
        rez *= i;
    }
    return rez;
}

double calcItem(double x, uint16_t n) {
    return pow(x, n) / static_cast<double>(fact(n));

}

double expn(double x, uint16_t count) {
    double summa = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        summa += calcItem(x, i);
    }
    return summa;
}

double sinn(double x, uint16_t count) {
    double summa = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        double term = sign * pown(x, 2*i+1) / static_cast<double>(fact(2*i+1));
        summa += term;
    }
    return summa;
}

double cosn(double x, uint16_t count) {
    double summa = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        double term = sign * pown(x, 2*i) / static_cast<double>(fact(2*i));
        summa += term;
    }
    return summa;
}
