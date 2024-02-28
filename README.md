# ADS-2 Реализация численных методов для трансцедентных функций


![GitHub pull requests](https://img.shields.io/github/issues-pr/NNTU-CS/ADS-2)
![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed/NNTU-CS/ADS-2)

Срок выполнения задания:

**по 10.03.24** ![Relative date](https://img.shields.io/date/1710104400)


## Задание

> Написать реализацию суммирования членов ряда для вычисления тренсцедентных функций

**Состав проекта**

```C++
   - double pown(double value, uint16_t n) - возведение числа в целую степень.
   - uint64_t fact(uint16_t n) - вычисление факториала чила n.
   - double calcItem(double x, uint16_t n) - вычисление члена ряда.
   - double expn(double x, uint16_t count) - вычисление значения функции exp(x) с суммированием count - членов ряда.
   - double sinn(double x, uint16_t count) - вычисление значения функции sin(x) с суммированием count - членов ряда.
   - double cosn(double x, uint16_t count) - вычисление значения функции cos(x) с суммированием count - членов ряда.   
 ```

## Пояснение

Для того, чтобы вычислить значения некоторых тренсцедентных функций (**exp**, **sin**, **cos**) применяется разложение в ряд:

![](./exp.png)
![](./sin.png)
![](./cos.png)

Задача состоит в том, чтобы реализовать вычисление функций с определенной точностью, определяемой числом слагаемых (чем больше, тем точнее).

- **pown(value,n)** - функция возведения **value** в степень **n**.
- **fact** - вычисление факториала.
- **calcItem(x, n)** - вычисление слагаемого ряда 

<img src="item.png" alt="drawing" width="100"/>

Остальные функции вычисляют значения **exp, sin, cos**, суммируя **count** - членов ряда. Чем больше **count**, тем точнее расчет. 


Функции должны располагаться в файле **src/alg.cpp**.
