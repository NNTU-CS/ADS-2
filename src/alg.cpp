// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1.0;
  }
  if (value == 0.0) {
	  return 0.0;
  }
  double result = 1.0;
  double base = value;
  while (n > 0) {
	  if (n & 1) {
		  result *= base;
	  }
	  base *= base;
	  n >>= 1; 
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n > 20) {
	  return 0; 
  }
  uint64_t result = 1;
  for (uint16_t i = 2; i <= n; ++i) {
	  result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) return 1.0; 
  uint64_t factorial = fact(n);
  if (factorial == 0) {
	  return 0.0; 
  }
  double power = pown(x, n);
  return power / static_cast<double>(factorial);
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
  for (uint16_t k = 0; k < count; ++k) {
	  uint16_t n = 2 * k + 1; 
	  double item = calcItem(x, n);
	  if (k % 2 == 0) {
		  sum += item;
	  }
	  else {
		  sum -= item;
	  }
  }
return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0.0;
  for (uint16_t k = 0; k < count; ++k) {
	  uint16_t n = 2 * k; 
	  double item = calcItem(x, n);
	  if (k % 2 == 0) {
		  sum += item;
	  }
	  else {
		  sum -= item;
	  }
  }
  return sum;
}
