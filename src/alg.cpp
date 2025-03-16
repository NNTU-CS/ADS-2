#include <cstdint>
#include <cmath>
#include "alg.h"
double pown(double value, uint16_t n) {
  if (n == 1)
    return value;
  else if (n == 0)
    return 1;
  else
    return value * pown(value, n-1);
}

uint64_t fact(uint16_t n) {
  if (n == 1)
    return 1;
  else if (n == 0)
    return 1;
  else
    return n * fact(n-1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  count--;
  else if (count == 0)
    return 1;
  else
    return calcItem(x, count) + expn(x, count);
}

double sinn(double x, uint16_t count) {
  if (count == 1)
    return calcItem(x, count);
  else if (count == 0)
    return 0;
  else
    return (pawn(-1, count)) * calcItem(x, count*2-1) + sinn(x, count-1);
}

double cosn(double x, uint16_t count) {
  if (count == 1)
    return 1;
  else if (count == 0)
    return 0;
  else
    return (pawn(-1, count)) * calcItem(x, count*2) + cosn(x, count-1);
}
