// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  while (n != 0){
    res *= value;
    n--;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint64_t fact = 1ж
  for (uint16_t i = 1; i <= n; i++){
    fact *= i;
  }
  return fact;
}

double calcItem(double x, uint16_t n) {


double expn(double x, uint16_t count) {
  double sum = 1.0; 
  double term = 1.0;

  for (uint16_t i = 1; i < count; i++) {
    term *= x / i;
    sum += term;  
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0.0; 
  double term = x; 

  for (uint16_t i = 1; i < count; i++) {
    sum += term; 
    term *= -x * x / ((2 * i) * (2 * i + 1)); 
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 1.0; 
  double term = 1.0; 

  for (uint16_t i = 1; i < count; i++) {
    term *= -x * x / ((2 * i - 1) * (2 * i)); 
    sum += term; 
  }
  return sum;
}
