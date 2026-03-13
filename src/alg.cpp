// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double resultat = 1;
  for (uint16_t i = 1; i <= n; i++) 
    resultat = resultat * value;
  return resultat;
}

uint64_t fact(uint16_t n) {
  uint64_t resultat = 1;
  for (uint16_t i = 1; i <= n; i++) 
    resultat = resultat * i;
  return resultat;
}

double calcItem(double x, uint16_t n) {
  double slogaemoeRiada = pown(x, n) / fact(n);
  return slogaemoeRiada;
}

double expn(double x, uint16_t count) {
  double exponenta = 1;
  for (uint16_t i = 1; i <= count; i++)
    exponenta += calcItem(x, i);
  return exponenta;
}

double sinn(double x, uint16_t count) {
  double sinus = x;
  char znak = -1;
  for (uint16_t i = 3; i <= count; i += 2) {
    sinus = sinus + (znak * calcItem(x, i));
    znak = znak * (-1);
  }
  return sinus;
}

double cosn(double x, uint16_t count) {
  double cosinus  = 1;
  char znak = -1;
  for (uint16_t i = 2; i <= count; i += 2) {
    cosinus += znak * calcItem(x, i);
  }
  return cosinus;
}
