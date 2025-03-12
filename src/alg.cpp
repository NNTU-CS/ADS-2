// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double newValue = 1.0;
if (n == 0) {
return 1.0;
}
for (uint64_t i = 0; i < n; i++) {
newValue *= value;
}
return newValue;
}

uint64_t fact(uint16_t n) {
if (n <= 1) {
return 1.0;
} else {
uint64_t res = 1;
uint64_t i = 1;
while (i <= n) {
res *= i;
i++;
}
return res;
}
}

double calcItem(double x, uint16_t n) {
double num = pown(x, n);
double denum = fact(n);
return num / denum;
}

double expn(double x, uint16_t count) {
double exp = 1.0;
for (uint64_t i = 1; i <= count; i++) {
exp += pown(x, i) / fact(i);
}
return exp;
}

double sinn(double x, uint16_t count) {
double sin = x;
for (uint64_t i = 2; i < count; i++) {
uint64_t znak = ((i % 2 == 0) ? 1 : -1);
sin += znak * pown(x, 2 * i) / calcItem(x, 2 * i + 1);
}
return sin;
}

double cosn(double x, uint16_t count) {
double cos = 1.0;
for (uint64_t i = 2; i < count; i++) {
uint64_t znak = ((i % 2 == 0) ? 1 : -1);
cos += znak * pown(x, 2 * i) / calcItem(x, 2 * i);
}
return cos;
}
