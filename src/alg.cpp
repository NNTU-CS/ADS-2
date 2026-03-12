// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double a=1;
  for(u_int16_t i=0;i<n;i++){
        a*=value;
    }
    return a;
}

uint64_t fact(uint16_t n) {
  if (n <= 1) return 1;
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x,n)/fact(n);
}

double expn(double x, uint16_t count) {
  double sum=0;
  for(uint16_t i=0;i<count;i++){
    sum+=calcItem(x,i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum=0;
   for(uint16_t i = 1; i <= count; i++) {  
        uint16_t exp = 2*i - 1;        
        double ter = pown(x, exp) / fact(exp);
        if(i % 2 == 1)  
            sum += ter;
        else            
            sum -= ter;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0;
    for(uint16_t i= 0; i < count; i++) {  
        uint16_t exp = 2*i;          
        double ter = pown(x, exp) / fact(exp);
        if(i % 2 == 0)  
            sum += ter;
        else           
            sum -= ter;
    }
    return sum;
}
