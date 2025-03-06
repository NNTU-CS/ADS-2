// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

long double pown(long double value, uint16_t n) {
    long double accumulator = 1.0L;
    for (uint16_t counter = 0; counter < n; ++counter) {
        accumulator *= value;
    }
    return accumulator;
}

uint64_t fact(uint16_t n) {
    uint64_t product = 1;
    for (uint16_t multiplier = 2; multiplier <= n; ++multiplier) {
        product *= multiplier;
    }
    return product;
}

long double calcItem(long double x, uint16_t n) {
    return pown(x, n) / static_cast<long double>(fact(n));
}

long double expn(long double x, uint16_t count) {
    long double totalSum = 1.0L;
    long double term = 1.0L;
    for (uint16_t iteration = 1; iteration < count; ++iteration) {
        term *= x / iteration;
        totalSum += term;
    }
    return totalSum;
}

long double sinn(long double x, uint16_t count) {
    long double seriesSum = 0.0L;
    for (uint16_t step = 0; step < count; ++step) {
        long double currentTerm = pown(-1.0L, step) * pown(x, 2 * step + 1);
        currentTerm /= static_cast<long double>(fact(2 * step + 1));
        seriesSum += currentTerm;
    }
    return seriesSum;
}

long double cosn(long double x, uint16_t count) {
    long double cumulativeSum = 0.0L;
    for (uint16_t index = 0; index < count; ++index) {
        long double termValue = pown(-1.0L, index) * pown(x, 2 * index);
        termValue /= static_cast<long double>(fact(2 * index));
        cumulativeSum += termValue;
    }
    return cumulativeSum;
}
