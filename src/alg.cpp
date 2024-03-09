// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  
  double result = 1.0;
  for (int i = 0; i < n; ++i){
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  
  int result = 1;
  for (int i = 1; i <= n; ++ i){
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  
  double result = 0.0;
  for (int i = 0; i < n; ++i){
    result += pown(x, i) / fact(i);
  }
  return result;
}

double expn(double x, uint16_t count) {
  
  return calcItem(x, n);
}

double sinn(double x, uint16_t count) {
  
  double result = 0.0;
  for (int i = 0; i < n; ++i){
    result += pown(-1, i) * pown(x, 2 * i + 1) / fact(2 * i + 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  
  double result = 0.0;
  for (int i = 0; i < n; ++i){
    result += pown(-1, i) * pown(x, 2 * i) / fact(2 * i);
  }
  return result;
}

int main(){
  double x = 0.5;
  int n = 10;
  std::cout << "e^x (approximation): " << expn(x, n) << std::endl;
  std::cout << "sin(x) (approximation): " << sinn(x, n) << std::endl;
  std::cout << "cos(x) (approximation): " << cosn(x, n) << std::endl;
  return 0;
}
