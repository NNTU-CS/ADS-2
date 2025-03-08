// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double baseNum, uint16_t powerLevel) {
  double total = 1.0;
  for (uint16_t step = 0; step < powerLevel; step++) {
    total *= baseNum;
  }
  return total;
}

uint64_t fact(uint16_t inputNum) {
  if (inputNum == 0 || inputNum == 1) {
    return 1;
  }
  uint64_t product = 1;
  for (uint16_t counter = 2; counter <= inputNum; counter++) {
    product *= counter;
  }
  return product;
}

double calcItem(double valueX, uint16_t termNum) {
  return pown(valueX, termNum) / fact(termNum);
}

double expn(double inputX, uint16_t termCount) {
  double sumResult = 1.0;
  double currentTerm = 1.0;
  for (uint16_t index = 1; index <= termCount; index++) {
    currentTerm *= inputX / index;
    sumResult += currentTerm;
  }
  return sumResult;
}

double sinn(double angleX, uint16_t termsQty) {
  double finalSum = 0.0;
  for (uint16_t pos = 0; pos < termsQty; pos++) {
    double currentTerm = calcItem(angleX, 2 * pos + 1);
    if (pos % 2 == 0) {
      finalSum += currentTerm;
    } else {
      finalSum -= currentTerm;
    }
  }
  return finalSum;
}

double cosn(double radianX, uint16_t termsNum) {
  double totalSum = 0.0;
  for (uint16_t iter = 0; iter < termsNum; iter++) {
    double nextTerm = calcItem(radianX, 2 * iter);
    if (iter % 2 == 0) {
      totalSum += nextTerm;
    } else {
      totalSum -= nextTerm;
    }
  }
  return totalSum;
}
