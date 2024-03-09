// Copyright 2022 NNTU-CS
#include "alg.h"

double pown(double value, uint16_t n){
    if (n == 0)
        return 1;
    else
        return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n){
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

double calcItem(double x, uint16_t n){
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count){
    double res = 1;
    for (uint16_t i = 1; i <= count; i++){
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count){
    double res1 = 0.0;
    for (uint16_t i = 0; i < count; i++){
        res1 += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i + 1);
    }
    return res1;
}

double cosn(double x, uint16_t count){
    double res2 = 0.0;
    for (uint16_t i = 0; i < count; i++){
        res2 += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i);
    }
    return res2;
}
