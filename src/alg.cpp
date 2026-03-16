// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
	if (n == 0) return 1.0;

	double ans = 1.0;
	for (uint16_t i = 0; i < n; i++) {
		ans *= value;
	}
	return ans;
}

uint64_t fact(uint16_t n) {
	if (n == 0 || n == 1) return 1;

	uint16_t ans = 1;
	for (uint16_t i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

double calcItem(double x, uint16_t n) {
	if (n == 0) return 1.0;
	return pown(x,n) / fact(n);
}

double expn(double x, uint16_t count) {
	if (count == 0) return 0.0;

	double ans = 0.0;
	for (uint16_t i = 0; i < count; i++) {
		ans += calcItem(x, i);
	}
	return ans;
}

double sinn(double x, uint16_t count) {
	if (count == 0) return 0.0;

	double ans = 0.0;
	for (uint16_t i = 0; i < count; i++) {
		uint16_t power = 2 * i + 1;
		double t = calcItem(x, power) / fact(power);

		if (i % 2 == 0) {
			ans += t;
		}
		else
		{
			ans -= t;
		}
	}
	return ans;
}

double cosn(double x, uint16_t count) {
	if (count == 0) return 0.0;
	double ans = 0.0;
	for (uint16_t i = 0; i < count; i++) {
		uint16_t power = 2 * i;
		double t = pown(x, power) / fact(power);
		if (i % 2 == 0) {
			ans += t;
		}
		else
		{
			ans -= t;
		}
	}
	return ans;
}
