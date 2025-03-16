// Copyright 2022 NNTU-CS
#include <cmath>
#include <iostream>


double fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fact(n-1) * n;
}

double pown(double value, uint16_t n) {
	double value2 = value;
	for (uint16_t i = 2; i <= n; ++i) {
		value *= value2;
	}
	return value;
}

double calcItem(double x, uint16_t n) {
	return (pown(x, n)) / (fact(n));
}

double expn(double x, uint16_t count) {
    double result = 0;
    for (int i = 1; i <= count; i++) {
        result += calcItem(x, i);
    }
    return result;
}

double sinn(double x, int count) {
    double result = 0;
    int sign = 1;
    for (int i = 1; i <= count; i++) {
        result += sign * (pow(x, (2*i - 1)) / fact(2*i - 1));
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    int sign = -1;
    for (int i = 1; i < count; i++) {
        res += sign * (pown(x, (2*i - 2)) / fact((2*i - 2)));
    }
    return res;
}
