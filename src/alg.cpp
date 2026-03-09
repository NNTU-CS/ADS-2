// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {

    double pwn = 1;
    for (int i = 0; i < n; ++i) {
        pwn *= value;
    }
    return pwn;

}

uint64_t fact(uint16_t n) {
    uint64_t ans_fact = 1;
    for (int i = 1; i <= n; ++i) {
        ans_fact *= i;
    }
    return ans_fact;
}

double calcItem(double x, uint16_t n) {
    double ansCalcItem = pown(x, n) / fact(n);
    return ansCalcItem;
}

double expn(double x, uint16_t count) {

    double ansexpn = 1;
    for (int i = 1; i <= count; ++i) {
        ansexpn += calcItem(x, i);
    }

    return ansexpn;
}

double sinn(double x, uint16_t count) {
    double ansSin = 0;
    for (int i = 1; i <= count; ++i) {
        ansSin = ansSin + pown(-1, i-1) * ((pown(x, 2 * i - 1) / fact(2 * i - 1)));
        std::cout << ansSin << std::endl;
    }
    return ansSin;

}

double cosn(double x, uint16_t count) {
    double ansCos = 0;
    for (int i = 1; i <= count; ++i) {
        ansCos += (pown(-1, i - 1) * (pown(x , 2 * i - 2) / fact(2 * i - 2)));
    }
    return ansCos;
}
