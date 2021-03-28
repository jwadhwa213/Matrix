//--------------------------------------------
//   Name: Jasmine Kaur Wadhwa
//   ID: 1619400
//   CMPUT 275, Winter 2021
//
//   Weekly Exercise #4
//--------------------------------------------

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <stdio.h>

using namespace std;


class Matrix{
/*This header file defines a class Matrix that works with the type float. The 
  class supports various operations as defined within the scope of the class. */
public:
	//constructors
	Matrix(size_t num_rows, size_t num_columns, float init);
	Matrix(size_t num_rows, size_t num_columns, float * arr_ptr);

	//copy constructor
	//makes a deep copy of the object passed to it as an argument rather than a 
	//shallow copy
	Matrix(const Matrix& mat);
	
	//transpose
	//makes a transpose matrix of the caller Matrix object and returns a new instance
	Matrix transpose() const;
	
	//submatrix
	//returns a new instance of the Matrix class containing a submatrix with rows of 
	//the caller matrix from row_start to (row_end -1) and columns from column_start to (column_end-1)
	Matrix submatrix(size_t row_start, size_t row_end,size_t column_start, size_t column_end) const;
	
	//addition
	//returns a new instance of the Matrix class after adding the matrices of the caller object and
	//the matrix passed to it as an argument.
	Matrix operator+(Matrix& rhs) const;

	//subtraction
	//returns a new instance of the Matrix class after subtracting the matrices of the caller object and
	//the matrix passed to it as an argument.
	Matrix operator-(Matrix rhs) const;

	//multiplication
	//returns a new instance of the Matrix class after multiplying the matrices of the caller object and
	//the matrix passed to it as an argument.
	Matrix operator*(const Matrix rhs) const;
	
	//unary negation
	//returns a new instance of the Matrix class after negating the matrix of the caller object.
	Matrix operator-() const;

	//bracket operator
	//returns a float pointer to a row of the matrix at the specified index
	//this is the non const version
	float* operator[](int index);

	//bracket operator
	//returns a float pointer to a row of the matrix at the specified index
	//this is the const version
	const float* operator[](int index) const;


	//desttructor
	//it frees all the allocated memory from the heap when the object goes out of scope
	~Matrix();

	//some attributes of the Matrix object
	size_t mat_rows,mat_columns;
	float **M;
	
};

//extraction
//This operator reads elements from the input stream and populates the matrix row by row
istream& operator>>(istream& in, Matrix& mat);

//insertion
//It prints the matrix row by row
ostream& operator<<(ostream& out, Matrix mat);

#endif