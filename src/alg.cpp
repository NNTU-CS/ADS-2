// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double p = value;
    for (uint64_t i = 2; i <= n; i++) {
        p *= value;
    }
    return p;
}

uint64_t fact(uint16_t n) {
    uint64_t p = 1;
    for (uint64_t i = 1; i <= n; i++) {
        p *= i;
    }
    return p;

}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(x);
}

double expn(double x, uint16_t count) {
    double e = 1;
    for (uint64_t i = 1; i <= count ; i++) {
        e += calcItem(x, count);
    }
    return e;

}

double sinn(double x, uint16_t count) {
    double si = 1;
    for (uint64_t i = 1; i <= count; i++) {
        si += pown(-1, i)* calcItem(x,2*i+1);
    }
    return si;
}

double cosn(double x, uint16_t count) {
    double co = 1;
    for (uint64_t i = 1; i <= count; i++) {
        co += pown(-1, i)* calcItem(x,2*i);
    }
    return co;
}
