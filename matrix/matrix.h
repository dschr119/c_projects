#pragma once

#include <vector>
#include <iostream>

class Matrix{

public:

  // constructors/destructor
  Matrix(){}
  Matrix( int, int );
  ~Matrix();

  // size and initialization
  void resize( int, int );
  int rows()const{ return size[0]; }
  int cols()const{ return size[1]; }

  // operations
  double& operator()( int, int )const;
  Matrix& operator=( const Matrix& );

  friend Matrix operator+( const Matrix&, const Matrix& );
  friend Matrix operator*( const Matrix&, const Matrix& );

private:

  void checkValid(int, int)const;

  // internal setters/getters
  void set( int, int, double )const;
  double get( int, int )const;

  std::vector<std::vector<double>*> data;
  int size[2] = {0, 0};

};
