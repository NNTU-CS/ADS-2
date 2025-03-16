// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 1){
      return value;
  }
  if (n == 0 || value == 1.0){
      return 1.0;
  }
  double res = 1.0;
  for (uint16_t i = 0; i < n; i++){
      res*=value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  uint16_t res = 1;
    for(uint16_t i = 1; i <= n; i++){
        res*=i;
    }
    return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x,n)/fact(n);
}

double expn(double x, uint16_t count) {
  double res = 1;
  for (uint16_t i = 1; i<=count; i++){
      res+=pown(x,i)/fact(i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  double sl = pown(-1,count-1)*(pown(x,2*count-1)/fact(2*count-1));
  for (uint16_t i = 3; i<=count; i+=2){
      res+=pown(x,i)/fact(i);
  }
  return x-(res+sl);
}

double cosn(double x, uint16_t count) {
  double res = 0;
  double sl = pown(-1,count-1)*(pown(x,2*count-2)/fact(2*count-2));
  for (uint16_t i = 2; i<=count; i+=2){
      res+=pown(x,i)/fact(i);
  }
  return 1-(res+sl);
}
