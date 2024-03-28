// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double res = 1;
    if (n == 0) {
        return 1;
    }
    if (n > 0) {
        for (uint64_t i = 0; i < n; i ++) {
            res *= value;
        }
    }
    return res;
}

uint64_t fact(uint16_t n) {
    uint64_t res = 1;
    for (int i = n; i > 1 ; i--) {
        res *= i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
    double chisl = pown(x, n);
    uint64_t znam = fact(n);
    return chisl / znam;
}

double expn(double x, uint16_t count) {
    double result = 1;
    for (int i = 1; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0;
    int arg = 1;
    for (int i = 0; i < count; i++) {
        double item = calcItem(x, 2 * i + 1) * arg;
        arg = -arg;
        result += item;
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 1;
    int arg = -1;
    for (int i = 2; i < 2*count; i += 2) {
        double item = calcItem(x, i) * arg;
        arg = -arg;
        result += item;
    }
    return result;
}
