// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
 double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;

uint64_t fact(uint16_t n) {
  def factorial(n):
    if n < 0:
        return "Факториал отрицательного числа не определен."
    elif n == 0:
        return 1
    else:
        result = 1
        for i in range(1, n + 1):
            result *= i
        return result

n = int(input("Введите число n: "))
print(f"Факториал = {factorial(n)}")

}

double calcItem(double x, double d, uint16_t n) {
    return a1 + (n - 1) * d;
double expn(double x, uint16_t count) {
    double sum = 1.0;
    double term = 1.0; 
    for (int n = 1; n <= count; ++n) {
        term *= x / n; 
        sum += term;   
    }

    return sum;
}

double sinn(double x, uint16_t count) {
  
 double sineValue = 0.0;
    for (int n = 0; n < terms; ++n) {
        
        sineValue += (pow(-1, n) * pow(x, (2 * n + 1))) / factorial(2 * n + 1);
    }
    return sineValue;
}

double cosn(double x, uint16_t count) {
 double result = 0.0;
    for (int n = 0; n < count; ++n) {
        // Члены ряда: (-1)^n * x^(2n) / (2n)!
        double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        result += term;
    }
    return result;
}
