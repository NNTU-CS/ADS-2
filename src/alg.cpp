// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 0; i < n; i++){
    result *= value;
  }
  return result;
}


uint64_t fact(uint16_t n) {
  if (n <= 1)
    return 1;
  else:
    return n * fact(n-1);
}


double calcItem(double x, uint16_t n) {
  double result = 1.0;
  for (uint16_t i = 1; i <= n; i++){
    result *= x / i;
  }
  return result;
}


double expn(double x, uint16_t count) {
  double result = 1.0;
  double date = 1.0;
  for (uint16_t n = 1; n <= count; n++){
    date *= x / n;
    result += date;
  }
  return result  
}


double sinn(double x, uint16_t count) {
  double result = 0.0;
  double date = x;
  for (uint16_t n = 1; n <= count; n++){
    if (n % 2 == 1) {
      result += date;
    } else {
      result -= date;
    }
    date = date * x * x / ((2*n) * (2*n + 1));
  }
  return result;    
}


double cosn(double x, uint16_t count) {
  double result = 1.0;
  double date = 1.0;
  for (uint16_t n = 1; n <= count; n++){
    if (n % 2 == 1) {
      result -= date;
    } else {
      result += date;
    }
    date = date * x * x / ((2*n) * (2*n - 1));
  }
  return result;  
}
