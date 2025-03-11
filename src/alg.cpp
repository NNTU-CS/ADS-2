// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>
#include "alg.h"
#include "math.h"

double pown(double value, uint16_t n) {
if (n == 0) {
return 1.0;
}
double res = 1.0;
for (uint16_t i = 0; i < n; ++i) {
res *= value;
}
return res;
}

uint64_t fact(uint16_t n) {
uint64_t factorial = 1;
for (uint16_t i = 1; i <= n; ++i) {
factorial *= i;
}
return factorial;
}

double calcItem(double x, uint16_t n) {
double item = 0.0;
item = pow(x, n) / fact(n);
return item;
}

double expn(double x, uint16_t count) {
double e = 1;
for (uint16_t n = 1; n < count + 1; ++n) {
e += (pow(x, n) / fact(n));
}
return e;
}

double sinn(double x, uint16_t count) {
double sin = 0.0;
for (uint16_t n = 0; n < count; ++n) {
sin += pow(-1, n) * pow(x, 2 * n + 1) / fact(2 * n + 1);
}
return sin;
}

double cosn(double x, uint16_t count) {
double cos = 1.0;
for (uint16_t n = 2; n < count + 1; ++n) {
cos += (pow(-1, n - 1) * pow(x, 2 * n - 2)) / fact(2 * n - 2);
}
return cos;
}
