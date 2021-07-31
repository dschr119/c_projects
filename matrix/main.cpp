#include <iostream>
#include "matrix.h"

int main() {

  Matrix<int> A(2, 2);
  Matrix<int> B(2, 2);
  Matrix<int> C(2, 2);
  Matrix<int> D(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;

  C(0, 0) = 1;
  C(0, 1) = 2;
  C(1, 0) = 3;
  C(1, 1) = 4;

  D(0, 0) = 1;
  D(0, 1) = 2;
  D(1, 0) = 3;
  D(1, 1) = 4;

  Matrix<Matrix<int>> AA(2, 2);
  AA(0, 0).resize(2, 2);
  AA(0, 1).resize(2, 2);
  AA(1, 0).resize(2, 2);
  AA(1, 1).resize(2, 2);

  AA(0, 0) = A;
  AA(0, 1) = B;
  AA(1, 0) = C;
  AA(1, 1) = D;

  std::cout << AA << std::endl;


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
