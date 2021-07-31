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
  Matrix<Type>& operator=( const Matrix<Type>& );

  template <class Type0>
  friend Matrix<Type0> operator+( const Matrix<Type0>&, const Matrix<Type0>& );
  template <class Type0>
  friend Matrix<Type0> operator*( const Matrix<Type0>&, const Matrix<Type0>& );
  template <class Type0>
  friend std::ostream& operator<<(std::ostream&, Matrix<Type0>&);

private:

  void checkValid(int, int)const;
  void checkNumeric()const;

  // internal setters/getters
  void set( int, int, Type& )const;
  Type get( int, int )const;

  // internal data
  std::vector<std::vector<Type>*> data;
  int size[2] = {0, 0};

};


/// misc functions

// multiplies two matrices and stores the result in given matrix
template <class Type>
void multiply( const Matrix<Type>& A, const Matrix<Type>& B, Matrix<Type>& result ){

  Type sum;

  for( int row=0; row<result.rows(); row++ ){
    for( int col=0; col<result.cols(); col++ ){
      // dotP A[row] and B[col]

      sum=0;
      for( int idx=0; idx<A.cols(); idx++ ){
        sum += A(row, idx) * B(idx, col);
      }
      result( row, col ) = sum;

    }
  }

}

/// constructors/destructors

template <class Type>
Matrix<Type>::Matrix( int rows, int columns ){
  resize( rows, columns );
}

template <class Type>
Matrix<Type>::~Matrix(){
  // delete pointers
  for( auto p : data ) delete p;
}

/// size/initialization methods

// this function resizes the matrix
template <class Type>
void Matrix<Type>::resize( int rows, int columns ){

  // ensure row and size are valid arguments
  if( rows <= 0 || columns <= 0 ){
    std::cout << "cannot resize - invalid dimension" << std::endl;
    throw;
  }

  // delete previous memory
  if(data.size())
    for( auto row : data )
      delete row;

  data.clear();

  // change size dimensions
  size[0] = rows;
  size[1] = columns;

  // resize vector vector
  for(int r=0; r<rows; r++)
    data.push_back( new std::vector<Type> );

  // resize each double vector
  for( auto row : data )
    row -> resize( columns );

}


/// operators
template <class Type>
Type& Matrix<Type>::operator()( int row, int column )const{

  checkValid(row, column);

  Type& address = data[row]->at(column);

  return address;
}


template <class Type>
Matrix<Type>& Matrix<Type>::operator=( const Matrix<Type>& B ){

  // resize current matrix to copy data
  if( rows() != B.rows() || cols() != B.cols() ){
    resize( B.rows(), B.cols() )
  }

  for(int r=0; r<rows(); r++)
    for(int c=0; c<cols(); c++)
      set( r, c, B(r, c) );

  return *this;
}


// friend function to add two matrices
template <class Type>
Matrix<Type> operator+( const Matrix<Type>& A, const Matrix<Type>& B ){

  if( A.rows() != B.rows() || A.cols() != B.cols() ){
    std::cout << "cannot add matrices of different sizes" << std::endl;
    throw;
  }

  Matrix<Type> result( A.rows(), A.cols() );
  for( int row_idx=0; row_idx < A.rows(); row_idx++ )
    for( int col_idx=0; col_idx < A.cols(); col_idx++ )
      result(row_idx, col_idx) = A(row_idx, col_idx) + B(row_idx, col_idx);

  return result;

}

// friend function to multiply two matrices
template <class Type>
Matrix<Type> operator*( const Matrix<Type>& A, const Matrix<Type>& B ){

  if( A.cols() != B.rows() ){
    std::cout << "cannot multiply matrices of sizes (" << A.rows() << " x " << A.cols();
    std::cout << ") and (" << B.rows() << " x " << B.cols() << ")" << std::endl;
    throw;
  }

  Matrix<Type> result( A.rows(), B.cols() );

  multiply( A, B, result );

  return result;

}

// this function produces the osteam output when we print the matrix
// it serves no purpose other than asthetic output
template <class Type>
std::ostream& operator<<(std::ostream& os, Matrix<Type>& mat){
  os << "[";
  for( int row_idx=0; row_idx < mat.rows()-1; row_idx++ ){
    for( int col_idx=0; col_idx < mat.cols()-1; col_idx++ )
      os << mat(row_idx, col_idx) << ", ";
    os << mat(row_idx, mat.cols()-1) << "\n";
  }
  for( int col_idx=0; col_idx < mat.cols()-1; col_idx++ )
    os << mat(mat.rows()-1, col_idx) << ", ";
  os << mat(mat.rows()-1, mat.cols()-1) << "]";

	return os;
}


/// setters/getters

// set the value of the row,column member of this matrix
template <class Type>
void Matrix<Type>::set( int row, int column, Type& value )const{

  //checkValid( row, column );

  (*data[row])[column] = value;
}

// get the value of the row,column member of this matrix
template <class Type>
Type Matrix<Type>::get( int row , int column )const{

  //checkValid( row, column );

  return (*data[row])[column];

}

/// other class functions

// checks if the given dimensions for a matrix are valid
template <class Type>
void Matrix<Type>::checkValid( int row, int column )const{
  if( row >= size[0] || column >= size[1] || row < 0 || column < 0 ){
    std::cout << "cannot access element (" << row << ", " << column << ")";
    std::cout << " of a " << size[0] << " x " << size[1] << " matrix" << std::endl;
    throw;
  }
}
