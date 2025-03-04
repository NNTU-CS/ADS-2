// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n){
  double a = 1;
  for (int i = 0; i < n; i++)
  {
  a *= value;
  }
  return a;
}

uint64_t fact(uint16_t n){
  if (n == 0){
  return 1;
  }
  else if (n == 1){
  return 1;
  }
  else{
  return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n){
  return pown(x,n)/fact(n);
}

double expn(double x, uint16_t count){
  double a = 1;
  for (int i = 1; i < count+1; i++){
  a += pown(x, i) / fact(i);
  }
  return a;
}

double sinn(double x, uint16_t count){
  double a = 0;
  for (int i = 1; i < count+1; i++){
  a = x + pown(-1, count - 1) * (pown(2, 2 * count - 1) / fact(2 * count - 1));
  }
  return a;
}

double cosn(double x, uint16_t count){
  double result = 0.0;
  for (int n = 0; n < count; n++) {
  double numerator = pown(-1, n) * pown(x, 2 * n - 2);
  double denominator = fact(2 * n - 2);
  result += numerator / denominator;
  }
  return result;
}
