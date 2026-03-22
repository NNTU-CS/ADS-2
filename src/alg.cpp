// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <iostream>

double pown(double value, uint16_t n) {
	if (n == 0) {
		return 1.0;
	}
	if (value == 0 && n == 0) {
		return 1.0;
	}
	if (n < 0) {
		uint16_t cur_res = 1.0;
		uint16_t a = -n;
		for (uint16_t i = 0; i < a; i++) {
			cur_res *= value;
		}
		if (cur_res == 0) {
			std::cout << "Error\n";
			return 0.0;
		}
		return 1.0 / cur_res;
	}
	double result = 1.0;
	
	for (uint16_t i = 0; i < n; i++) {
		result = result * value;
	}
	return result;
}

uint64_t fact(uint16_t n) {
	if (n == 0) {
		return 1;
	}
	if (n > 20) {
		return 0;
	}
	uint64_t result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

double calcItem(double x, uint16_t n) {
	double exponent = pown(x, n);
	uint64_t factorial = fact(n);
	return exponent/static_cast<double>(factorial);
}

double expn(double x, uint16_t count) {
	double sum = 0.0;
	for (uint16_t n = 0; n < count; ++n) {
		sum += calcItem(x, n);
	}
	return sum;
}

double sinn(double x, uint16_t count) {
	double sum = 0.0;
	for (uint16_t n = 0; n < count; ++n) {
		uint16_t index = 2 * n + 1;
		double numerator = pown(x, index);
		uint16_t denominator = fact(index);
		double sign;
		if (n % 2 == 0) {
			sign = 1.0;
		} else {
			sign = -1.0;
		}
		sum += sign * (numerator / denominator);
	}
	return sum;
}

double cosn(double x, uint16_t count) {
	double sum = 0.0;
	for (uint16_t n = 0; n < count; ++n) {
		uint16_t index = 2 * n;
		double numerator = pown(x, index);
		uint16_t denominator = fact(index);
		double sign;
		if (n % 2 == 0) {
			sign = 1.0;
		}
		else {
			sign = -1.0;
		}
		sum += sign * (numerator / denominator);
	}
	return sum;
}
