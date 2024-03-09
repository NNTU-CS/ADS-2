// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double start_value = value;
    if (n == 0) {
        return 1;
    }
    for (int i = 1; i < n; i++) {
        value *= start_value;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    uint64_t return_value = 1;
    for (int i = 1; i <= n; i++) {
        return_value = return_value * i;
    }
    return return_value;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double value_e = 1;
    for (int i = 1; i <= count; i++) {
        value_e += calcItem(x, i);
    }
    return value_e;
}

double sinn(double x, uint16_t count) {
    double value_sinn = 0;
    for (int i = 1; i <= count; i++) {
        value_sinn += pown(-1 , i - 1) * calcItem(x, i * 2 - 1);
    }
    return value_sinn;
}

double cosn(double x, uint16_t count) {
    double value_cosn = 0;
    for (int i = 1; i <= count; i++) {
        value_cosn += pown(-1, i - 1) * calcItem(x, i * 2 - 2);
    }
    return value_cosn;
}
