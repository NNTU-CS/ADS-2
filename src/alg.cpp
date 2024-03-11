// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (int i = 1; i <= n; ++i) {
    res *= value;
  }
  return res;
}


uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  if (n == 0) {
    return 1;
  }
  double head = 1;
  int tails = 1;
  for (int i = 1; i <= n; ++i) {
    head *= x;
    tails *= i;
  }
  double res = static_cast<double>(head) / static_cast<double>(tails);
  return res;
}

double expn(double x, uint16_t count) {
  if (count == 1) {
    return 1;
  }
  double res = 1;
  double cur_num = 1;
  for (int i = 1; i < count+1; ++i) {
    cur_num *= x;
    cur_num /= i;
    res += cur_num;
  }
  return res;
}

double sinn(double x, uint16_t count) {
  if (count == 1) {
    return x;
  }
  double res = x;
  double cur_num = x;
  int i = 2;
  while (count > 0) {
    cur_num *= x * x;
    cur_num = (cur_num / i) / (i + 1);
    i += 2;
    cur_num *= -1;
    res += cur_num;
    --count;
  }
  return res;
}

double cosn(double x, uint16_t count) {
  if (count == 1) {
    return 1;
  }
  double res = 1;
  double cur_num = 1;
  int i = 1;
  while (count > 1) {
    cur_num *= x * x;
    cur_num = (cur_num / i) / (i + 1);
    i += 2;
    cur_num *= -1;
    res += cur_num;
    --count;
  }
  return res;
}


