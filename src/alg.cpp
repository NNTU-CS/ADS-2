// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
	double result = 1;
	if (n == 0) {
		return 1.0;
	}
	else {
		for (int i = 0; i < n; i++)
			result *= value;
	}
	return result;
}

uint64_t fact(uint16_t n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	if (n > 1) {
		return n * fact(n - 1);
	}
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
	double result = 0;
	for (uint64_t i = 0; i <= count; i++) {
		result += (pown(x, i) / fact(i));
	}    
	return result;
}

double sinn(double x, uint16_t count) {
	double result = 0;
	double k = 0;    
	for (uint64_t i = 1; i <= count; i++) {
		k += 1;        
		result += pown(-1, k - 1) * ((pown(x, 2 * i - 1) / fact(2 * i - 1)));
	}    
	return result;
}

double cosn(double x, uint16_t count) {
	double result = 0;
	double k = 0;    
	for (uint64_t i = 1; i <= count; i++) {
		k += 1;        
		result += pown(-1, k - 1) * ((pown(x, 2 * i - 2) / fact(2 * i - 2)));
	}    
	return result;
}
