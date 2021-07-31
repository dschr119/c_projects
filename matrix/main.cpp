#include <iostream>
#include "matrix.h"

int main() {

  Matrix A(2, 2);
  Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;

  Matrix C(2, 2);
  C = A * B;

  std::cout << C(0, 0) << std::endl;

  std::cout << "ran...\n";
}
