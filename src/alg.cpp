// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    long double accumulator = 1.0L;
    for (uint16_t counter = 0; counter < n; ++counter) {
        accumulator *= static_cast<long double>(value);
    }
    return static_cast<double>(accumulator);
}

uint64_t fact(uint16_t n) {
    uint64_t product = 1;
    for (uint16_t multiplier = 2; multiplier <= n; ++multiplier) {
        product *= multiplier;
    }
    return product;
}

double calcItem(double x, uint16_t n) {
    long double numerator = pown(static_cast<long double>(x), n);
    long double denominator = static_cast<long double>(fact(n));
    return static_cast<double>(numerator / denominator);
}

double expn(double x, uint16_t count) {
    long double totalSum = 1.0L;
    long double term = 1.0L;
    for (uint16_t iteration = 1; iteration < count; ++iteration) {
        term *= static_cast<long double>(x) / iteration;
        totalSum += term;
    }
    return static_cast<double>(totalSum);
}

double sinn(double x, uint16_t count) {
    long double seriesSum = 0.0L;
    for (uint16_t step = 0; step < count; ++step) {
        long double currentTerm = pown(-1.0L, step);
        currentTerm *= pown(static_cast<long double>(x), 2 * step + 1);
        currentTerm /= static_cast<long double>(fact(2 * step + 1));
        seriesSum += currentTerm;
    }
    return static_cast<double>(seriesSum);
}

double cosn(double x, uint16_t count) {
    long double cumulativeSum = 0.0L;
    for (uint16_t index = 0; index < count; ++index) {
        long double termValue = pown(-1.0L, index);
        termValue *= pown(static_cast<long double>(x), 2 * index);
        termValue /= static_cast<long double>(fact(2 * index));
        cumulativeSum += termValue;
    }
    return static_cast<double>(cumulativeSum);
}
