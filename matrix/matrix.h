#pragma once

#include <vector>
#include <iostream>

template<class Type>
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
  Type& operator()( int, int )const;
  Matrix& operator=( const Matrix& );

  friend Matrix operator+( const Matrix&, const Matrix& );
  friend Matrix operator*( const Matrix&, const Matrix& );

private:

  void checkValid(int, int)const;
  void checkNumeric()const;

  // internal setters/getters
  void set( int, int, Type )const;
  double get( int, int )const;

  // internal data
  std::vector<std::vector<Type>*> data;
  int size[2] = {0, 0};
  bool is_numeric = NULL;

};
