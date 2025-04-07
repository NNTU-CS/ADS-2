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

double calcItem(double x, uint16_t n) {
 def calcItem(n):
    if n <= 0:
        raise ValueError("n должно быть больше 0")
    return 1 / (n ** 2)
}

double expn(double x, uint16_t count) {
    double sum = 1.0; // Начнем с первого члена ряда, который равен 1
    double term = 1.0; // Инициализируем первый член ряда

    for (int n = 1; n <= count; ++n) {
        term *= x / n; // Вычисляем n-ый член ряда
        sum += term;   // Добавляем член к сумме
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
