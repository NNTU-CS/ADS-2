// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>

double pown(double value, uint16_t n) {
    double res = 1;
    for(int i=1; i < n; i++){
        res = res * value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    if(n == 1){
        return 1;
    }
    else{
        return n * fact(n-1);
    }

}

double calcItem(double value, uint16_t n) {
    uint64_t res = pown(value, n) / fact(n);
    return res;
}


double expn(double x, uint16_t count) {
    double res = 0.0;
    for (int i = 0; i < count; i++) {
        res += pow (x, i) / tgamma(i+1);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = x;
    double t = x;
    for (uint16_t i = 1; i < count; i++) {
        t *= -x * x / ((2 * i + 1) * (2 * i));
        res += t;
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    double t = 1;
    for (uint16_t i = 1; i < count; i++) {
        t *= -x * x / ((2 * i) * (2 * i - 1));
        res+= t;
    }
    return res;
}
