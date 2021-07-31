#include <iostream>
#include "matrix.h"

void submatrix( Matrix<int>&A, Matrix<int>& B, int col_idx ){
  int t_c=-1;
  for( int subcol_idx=0; subcol_idx < B.cols()-1; subcol_idx++ ){
    t_c++;
    if( subcol_idx == col_idx )
      t_c++;
    for( int subrow_idx=0; subrow_idx < B.rows()-1; subrow_idx++ ){
      A( subrow_idx, subcol_idx ) = B( subrow_idx+1, t_c );
    }
  }
}

int main() {

  Matrix<int> A(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  //std::cout << A.det() << std::endl;
  std::cout << A.det() << std::endl;

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
