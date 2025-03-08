// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) return 1.0;
    double accumulator = value;
    uint16_t counter = 1;
    while (counter < n) {
        accumulator *= value;
        counter++;
    }
    return accumulator;
}

uint64_t fact(uint16_t n) {
    uint64_t product = 1;
    uint16_t multiplier = 2;
    while (multiplier <= n) {
        product *= multiplier;
        multiplier++;
    }
    return product;
}

double calcItem(double x, uint16_t n) {
    double numerator = pown(x, n);
    double denominator = fact(n);
    return numerator / denominator;
}

double expn(double x, uint16_t count) {
    double totalSum = 1.0;
    uint16_t iteration = 1;
    while (iteration <= count) {
        totalSum += calcItem(x, iteration);
        iteration++;
    }
    return totalSum;
}

double sinn(double x, uint16_t count) {
    double seriesSum = x;
    uint16_t step = 2;
    while (step <= count) {
        double currentTerm = pown(-1, step - 1);
        currentTerm *= pown(x, 2 * step - 1);
        currentTerm /= fact(2 * step - 1);
        seriesSum += currentTerm;
        step++;
    }
    return seriesSum;
}

double cosn(double x, uint16_t count) {
    double cumulativeSum = 1.0;
    uint16_t index = 2;
    while (index <= count) {
        double termValue = pown(-1, index - 1);
        termValue *= pown(x, 2 * index - 2);
        termValue /= fact(2 * index - 2);
        cumulativeSum += termValue;
        index++;
    }
    return cumulativeSum;
}
