// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
	double newValue = 0.0;
	for (int i = 0; i < n; i++) {
		newValue *= value;
	}
	return newValue;
	if (n < 0) return 1;
}

uint64_t fact(uint16_t n) {
	if (n <= 1)
		return 1.0;
	else {
		uint64_t res = 1;
		int i = 1;
		while (i <= n) {
			res *= i;
			i++;
		}
		return res;
	}
}

double calcItem(double x, uint16_t n) {
	double num = pown(x, n);
	double denum = fact(n);
	return num / denum;
}

double expn(double x, uint16_t count) {
	double exp = 1;
	for (int i = 0; i <= count; i++) {
		for (int i = 0; i <= count; i++) {
			exp += pown(x, i) / fact(i);
		}
		return exp;
	}
}

double sinn(double x, uint16_t count) {
  	double znak;
	if (x > 0) {
		znak = 1;
	} else if ( x < 0) {
		znak = -1;
	} else {
		znak = 0;
	}
	double sin = 0;
	for (int i = 0; i <= count; i++) {
		sin += znak * pown(x, 2 * i + 1) / fact(2 * i + 1);
	}
	return sin;
}

double cosn(double x, uint16_t count) {
	double znak;
	if (x > 0) {
		znak = 1;
	}
	else if (x < 0) {
		znak = -1;
	}
	else {
		znak = 0;
	}
	double cos = 0;
	for (int i = 0; i <= count; i++) {
		cos += znak * pown(x, 2 * i) / fact(2 * i);
	}
}
