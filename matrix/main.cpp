#include <iostream>
#include "matrix.h"

int main() {

  Matrix<double> A(3, 3);
  Matrix<double> B(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 50;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B = A.inverse();

  //std::cout << A.det() << std::endl;
  std::cout << B << std::endl;

  /* // OG driver code
  Matrix<int> A(2, 2);
  Matrix<int> B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;

  Matrix<int> C(2, 2);
  C = A * B;

  std::cout << C << std::endl;
  */
}
