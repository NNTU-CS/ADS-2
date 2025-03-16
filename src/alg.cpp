// Copyright 2022 NNTU-CS
#include <cmath>
#include <iostream>

double pown(double num, uint16_t power) {
    double base = num;
    for (uint16_t i = 2; i <= power; ++i) {
        num *= base;
    }
    return num;
}

uint64_t fact(uint16_t num) {
    if (num == 1) {
        return 1;
    } else {
        return fact(num - 1) * num;
    }
}

double calcItem(double val, uint16_t term) {
    return (pown(val, term)) / (fact(term));
}

double expn(double val, uint16_t terms) {
    double result = 1;
    for (uint16_t i = 1; i <= terms; ++i) {
        result += calcItem(val, i);
    }
    return result;
}

double sinn(double val, uint16_t terms) {
    double sum = 0;
    uint16_t index = 1;
    for (uint16_t i = 1; i <= terms * 2; i += 2) {
        if (index % 2 == 0) {
            sum -= calcItem(val, i);
        } else {
            sum += calcItem(val, i);
        }
        index++;
    }
    return sum;
}

double cosn(double val, uint16_t terms) {
    double sum = 1;
    uint16_t index = 1;
    for (uint16_t i = 2; i < terms * 2; i += 2) {
        if (index % 2 != 0) {
            sum -= calcItem(val, i);
        } else {
            sum += calcItem(val, i);
        }
        index++;
    }
    return sum;
}
