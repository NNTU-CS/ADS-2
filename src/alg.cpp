// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double newvalue = 1.0;
  while (n > 0) {
    newvalue *= value;
    n--;
  }
  return newvalue;
}

uint64_t fact(uint16_t n) {
  uint64_t factn = 1;
  while (n > 0) {
    factn *= n;
    n--;
  }
  return factn;
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double expanent = 1.0;
  for (uint64_t n = 1; n <= count; n++){
    expanent += calcItem(x, n);
  }
  return expanent;
}

double sinn(double x, uint16_t count) {
  double sinus = 0;
  while (count > 0) {
    sinus += pown(-1.0, count - 1) * calcItem(x, (2 * count - 1));
    count--;
  }
  return sinus;
}

double cosn(double x, uint16_t count) {
  double cosinus = 0;
  while (count > 0) {
    cosinus += pown(-1.0, count - 1) * calcItem(x, (2 * count - 2));
    count--;
  }
  return cosinus;
}
