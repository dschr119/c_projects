#include "Matrix.h"

/// misc functions

// multiplies two matrices and stores the result in given matrix
void multiply( const Matrix& A, const Matrix& B, Matrix& result ){

  double sum;

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

Matrix::Matrix( int rows, int columns ){
  resize( rows, columns );
}

Matrix::~Matrix(){
  // delete pointers
  for( auto p : data ) delete p;
}

/// size/initialization methods

// this function resizes the matrix
void Matrix::resize( int rows, int columns ){

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
    data.push_back( new std::vector<double> );

  // resize each double vector
  for( auto row : data )
    row -> resize( columns );

}


/// operators


double& Matrix::operator()( int row, int column )const{

  checkValid(row, column);

  double& address = data[row]->at(column);

  return address;
}

Matrix& Matrix::operator=( const Matrix& B ){

  if( rows() != B.rows() || cols() != B.cols() ){
    std::cout << "cannot copy matrices of different sizes" << std::endl;
    throw;
  }

  for(int r=0; r<rows(); r++)
    for(int c=0; c<cols(); c++)
      set( r, c, B(r, c) );

  return *this;

}


// friend function to add two matrices
Matrix operator+( const Matrix& A, const Matrix& B ){

  if( A.rows() != B.rows() || A.cols() != B.cols() ){
    std::cout << "cannot add matrices of different sizes" << std::endl;
    throw;
  }

  Matrix result( A.rows(), A.cols() );
  for( int row_idx=0; row_idx < A.rows(); row_idx++ )
    for( int col_idx=0; col_idx < A.cols(); col_idx++ )
      result(row_idx, col_idx) = A(row_idx, col_idx) + B(row_idx, col_idx);

  return result;

}

// friend function to multiply two matrices
Matrix operator*( const Matrix& A, const Matrix& B ){

  if( A.cols() != B.rows() ){
    std::cout << "cannot multiply matrices of sizes (" << A.rows() << " x " << A.cols();
    std::cout << ") and (" << B.rows() << " x " << B.cols() << ")" << std::endl;
    throw;
  }

  Matrix result( A.rows(), B.cols() );

  multiply( A, B, result );

  return result;

}

/// setters/getters

// set the value of the row,column member of this matrix
void Matrix::set( int row, int column, double value )const{

  checkValid( row, column );

  (*data[row])[column] = value;
}

// get the value of the row,column member of this matrix
double Matrix::get( int row , int column )const{

  checkValid( row, column );

  return (*data[row])[column];

}

/// other class functions

// checks if the given dimensions for a matrix are valid
void Matrix::checkValid( int row, int column )const{
  if( row >= size[0] || column >= size[1] || row < 0 || column < 0 ){
    std::cout << "cannot access element (" << row << ", " << column << ")";
    std::cout << " of a " << size[0] << " x " << size[1] << " matrix" << std::endl;
    throw;
  }
}
