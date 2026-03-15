// Copyright 2022 NNTU-CS
#include "alg.h"
#include <iostream>

int main() {
  double val = 1.0;
  uint16_t steps = 10;
  std::cout << "Test Taylor for x = " << val << std::endl;
  std::cout << "Exp: " << expn(val, steps) << std::endl;
  std::cout << "Sin: " << sinn(val, steps) << std::endl;
  std::cout << "Cos: " << cosn(val, steps) << std::endl;
  return 0;
}
