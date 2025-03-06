// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double accumulator = 1.0;
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

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    long double totalSum = 0.0;
    for (uint16_t iteration = 0; iteration < count; ++iteration) {
        totalSum += calcItem(x, iteration);
    }
    return static_cast<double>(totalSum);
}

double sinn(double x, uint16_t count) {
    long double seriesSum = 0.0;
    for (uint16_t step = 0; step < count; ++step) {
        long double currentTerm = pown(-1, step) * pown(x, 2 * step + 1);
        currentTerm /= static_cast<long double>(fact(2 * step + 1));
        seriesSum += currentTerm;
    }
    return static_cast<double>(seriesSum);
}

double cosn(double x, uint16_t count) {
    long double cumulativeSum = 0.0;
    for (uint16_t index = 0; index < count; ++index) {
        long double termValue = pown(-1, index) * pown(x, 2 * index);
        termValue /= static_cast<long double>(fact(2 * index));
        cumulativeSum += termValue;
    }
    return static_cast<double>(cumulativeSum);
}
