// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
        double Result = 1.0;
        uint16_t i = 0;
        for (i = 0; i < n; ++i) {
         Result = value * Result;
         }
         return Result;
}

uint64_t fact(uint16_t n) {
        uint64_t Result = 1;
        uint16_t i = 0;
        for (i = 1; i <= n; ++i) {
             Result = i * Result;
         }
         return Result;
}

double calcItem(double x, uint16_t n) {
           double Result = 0;
            Result = pown(x, n) / fact(n);
            return Result;
}

double expn(double x, uint16_t count) {
            double Result = 0;
             uint16_t i = 0;
           for (i = 0; i <= count; i++) {
                 Result = Result + calcItem(x, i);
                }
           return Result;
}

double sinn(double x, uint16_t count) {
        double Result = 0.0;
        uint16_t i = 0;
        for (i = 0; i < count; ++i) {
                if (i % 2 == 0) {
                        Result = Result + (1.0 * calcItem(x, 2 * i + 1));
                } else {
                        Result = Result + (-1.0 * calcItem(x, 2 * i + 1));
                       }
              }
           return Result;
}

double cosn(double x, uint16_t count) {
        double Result = 0.0;
        uint16_t i = 0;
        for (i = 0; i < count; i++) {
                if (i % 2 == 0) {
                        Result = Result + (1.0 * calcItem(x, 2 * i));
                } else {
                        Result = Result + (-1.0 * calcItem(x, 2 * i));
                   }
          }
          return Result;
}
