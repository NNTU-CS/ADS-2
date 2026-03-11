// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double result = 1.0;
    while (n != 0) {
        result *= value;
        n--;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t facterial = 1;
    for (uint16_t i = n; i > 0; i--) {
        facterial *= i;
    }
    return facterial;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double expanenta = 1.0;
    for (uint16_t i = 1; i <=count ; i++) {
        expanenta += calcItem(x, i);
    }
    return expanenta;
}

double sinn(double x, uint16_t count) {
    double sinus = 0.0;
    for (uint16_t i = 1, n = 0; n < count; i += 2, n++) {
        sinus += (pown(x, i) / static_cast<double>(fact(i))) * pown(-1, n);
    }
    return sinus;
}

double cosn(double x, uint16_t count) {
    double cosinus = 0.0;
    for (uint16_t i = 0, n = 0; n < count; i += 2, n++) {
        cosinus += (pown(x, i) / static_cast<double>(fact(i))) * pown(-1, n);
    }
    return cosinus;
}
