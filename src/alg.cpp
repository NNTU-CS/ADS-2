// Copyright 2022 NNTU-CS
#include <iostream>
#include <cmath>
#include <cstdint>
#include "alg.h"
using namespace std;

double pown(double value, uint16_t n) {
  double result = 1.0;
  for (int i = 0; i < n; i++){
    result *= x;
  }
  return result;
}


uint64_t fact(uint16_t n) {
int result = 1;
  for (int i = 1; i <= n; ++i){
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  double result = 0.0;
  for (int i = 0; i < n; ++i){
    result += power(x, i) / fact(i);
  }
  return result;
}

double expn(double x, uint16_t count) {
  return calcItem(x, n);
}

double sinn(double x, uint16_t count) {
  double result = 0.0;
  for (int i = 0; i < n; ++i){
    result += power(-1, i) * power(x, 2 * i + 1) / fact(2 * i + 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0.0;
  for (int i = 0; i < n; ++i){
    result += power(-1, i) * power(x, 2 * i) / fact(2 * i);
  }
  return result;
}

int main(){
  double x = 0.5;
  int n = 10;

  cout << "e^x (approximation): " << expn(x, n) << endl;
  cout << "sin(x) (approximation): " << sinn(x, n) << endl;
  cout << "cos(x) (approximation): " << cosn(x, n) << endl;
  
  return 0;
}

