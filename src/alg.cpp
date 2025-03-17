// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) { return 1.0; }
	double a = value;
	for (uint16_t i = 1; i < n; i++) {
		value = value * a;
	}
	return value;
	return 0.0;
}

uint64_t fact(uint16_t n) {
	if (n == 1 || n == 0) {
		return 1.0;
	}
	uint64_t f = 1;
	for (uint16_t i = 2; i <= n; i++) {
		f *= i;
	}
	return f;
	return 0.0;
}

double calcItem(double x, uint16_t n) {
	return (pown(x, n) / fact(n));
	return 0.0;
}

double expn(double x, uint16_t count) {
	double e = 1;
	for (uint16_t i = 1; i <= count; i++) {
		e += (pown(x, i) / fact(i));
	}
	return e;
	return 0.0;
}

double sinn(double x, uint16_t count) {
	double s = x;
	for (uint16_t i = 1; i <= count; i++) {
		s += (pown(-1, count - 1) * (pown(x, 2 * count - 1) / fact(2 * count - 1)));
	}
	return s;
	return 0.0;
}

double cosn(double x, uint16_t count) {
	double s = 1;
	for (uint16_t i = 1; i <= count; i++) {
		s += (pown(-1, count - 1) * (pown(x, 2 * count - 2) / fact(2 * count - 2)));
	}
	return s;
	return 0.0;
}
