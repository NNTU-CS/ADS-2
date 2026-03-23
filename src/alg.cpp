// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
    double pown2 = pown(value, n / 2);
    if (n % 2 == 0){
        return pown2 * pown2;
    }
    else {
        return value * pown2 * pown2;
    }
  return 0.0;
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  if (n == 1) return 1;
  if (n > 1) {
      return n * fact(n - 1);
  }
  return 0.0;
}

double calcItem(double x, uint16_t n) {
  double rezalt = pown(x,n)/fact(n);
  return rezalt;
}

double expn(double x, uint16_t count) {
  double summ = 1.0;
  double slag = 1.0;
  for (int i = 1; i <= count; ++i){
      slag *= x / i;
      summ += slag;
  }
  return summ;
}

double sinn(double x, uint16_t count) {
  double summ = x;
  double slag = x;
  if (count == 0) return 0;
  for (int i = 1; i < count; ++i){
      slag *= -1 * x * x / ((2 * i) * (2 * i + 1));
      summ += slag;
  }
  return summ;
}

double cosn(double x, uint16_t count) {
  double summ = 1.0;
  double slag = 1.0;
  if (count == 0) return 0;
  for (int i = 1; i < count; ++i){
      slag *= -1 * x * x / ((2 * i -1) * (2 * i));
      summ += slag;
  }
  return summ;
}
