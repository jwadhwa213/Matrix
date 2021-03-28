//--------------------------------------------
//   Name: Jasmine Kaur Wadhwa
//   ID: 1619400
//   CMPUT 275, Winter 2021
//
//   Weekly Exercise #4
//--------------------------------------------

#include "matrix.h"
#include <iostream>

using namespace std;


Matrix::Matrix(size_t num_rows, size_t num_columns, float init)
{/*This constructor allocates dynamic memory to the Matrix M of the caller object
   and initializes each of its elements to init.*/

	//allocating memory using new
	M=new float*[num_rows];
	for(int i=0;i<num_rows;i++)
	{
		M[i]=new float[num_columns];
	}
	//initializing the attributes mat_rows and mat_columns of the object
	mat_rows=num_rows;
	mat_columns=num_columns;

	//initializing each element of the matrix to init
	for(int i=0;i<num_rows;i++)
	{
		for(int j=0;j<num_columns;j++)
		{
			M[i][j]=init;
		}
	}
}

Matrix::Matrix(size_t num_rows, size_t num_columns, float * arr_ptr)
{/*This constructor allocates dynamic memory to the Matrix M of the caller object
   and initializes each of its elements using an array of size num_rows*num_columns,
   a pointer to which is passed as an argument.*/

	//allocating memory using new
	M=new float*[num_rows];
	for(int i=0;i<num_rows;i++)
	{
		M[i]=new float[num_columns];
	}

	//initializing the attributes mat_rows and mat_columns of the object
	mat_rows=num_rows;
	mat_columns=num_columns;
	int num=0;

	//initializing each element of the matrix row by row using the pointer 
	//to array
	for(int i=0;i<num_rows;i++)
	{
		for(int j=0;j<num_columns;j++)
		{

			M[i][j]=*(arr_ptr+num);
			num+=1;
		}
	}

}
Matrix::Matrix(const Matrix& mat)
{   //copy constructor
	//makes a deep copy of the object passed to it as an argument rather than a 
	//shallow copy

	//copying the attributes mat_rows and mat_columns of the object passed to it,
	// to the caller object
	mat_rows=mat.mat_rows;
	mat_columns=mat.mat_columns;
	
	//allocating memory to the matrix using new
	M=new float*[mat_rows];
	for(int i=0;i<mat_rows;i++)
	{
		M[i]=new float[mat_columns];
	}

	//making a deep copy of the elements of the matrix
	for(int i=0;i<mat_rows;i++)
	{
		for(int j=0;j<mat_columns;j++)
		{
			M[i][j]=mat.M[i][j];
		}
	}
}

//transpose
Matrix Matrix::transpose() const
{//makes a transpose matrix of the caller Matrix objec by turning rows into columns
// and returns a new instance

	size_t rows,columns;
	rows=mat_rows;
	columns=mat_columns;
	float array[rows*columns]={};
	int num=0;
	for(int i=0;i<columns;i++)
	{
		for(int j=0;j<rows;j++)
		{
			array[num]=M[j][i];
			num+=1;
		}
	}
	//creating a new instance T by turning rows*columns by using a constructor
	Matrix T=Matrix(columns,rows,array);
	return T;
}
//submatrix
Matrix Matrix::submatrix(size_t row_start, size_t row_end,size_t column_start, size_t column_end) const{
	//submatrix
	//returns a new instance of the Matrix class containing a submatrix with rows of 
	//the caller matrix from row_start to (row_end -1) and columns from column_start to (column_end-1)

	//initializing the number of rows and columns of the submatrix
	size_t rows=row_end-row_start;
	size_t columns=column_end-column_start;

	//instanciating a new Matrix object to store the submatrix
	Matrix sub=Matrix(rows,columns,0.0);

	//reading from the caller Matrix and storing the elements into the submatrix object
	int r=0,c=0;
	for(int i=row_start;i<row_end;i++)
	{
		for(int j=column_start;j<column_end;j++)
		{
			sub.M[r][c]=M[i][j];
			c+=1;
		}
		r+=1;
		c=0;
	}
	return sub;

}

//addition
Matrix Matrix::operator+(Matrix& rhs) const
{   //addition
	//returns a new instance of the Matrix class after adding the matrices of the caller object and
	//the matrix passed to it as an argument.
	size_t rows,columns;
	rows=mat_rows;
	columns=mat_columns;
	//creating a new instance
	Matrix add=Matrix(rows,columns,0.0);
	
	//performing the element by element addition
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			add.M[i][j]=M[i][j]+rhs.M[i][j];
			
		}
	}
	return add;
}
//subtraction
Matrix Matrix::operator-(const Matrix rhs) const
{//subtraction
	//returns a new instance of the Matrix class after subtracting the matrices of the caller object and
	//the matrix passed to it as an argument.
	size_t rows,columns;
	rows=mat_rows;
	columns=mat_columns;
	//creating a new instance
	Matrix subt=Matrix(rows,columns,0.0);


	//logic to perform the matrix subtraction
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			subt.M[i][j]=M[i][j]-rhs.M[i][j];
		}
	}
	return subt;
}
//multiplication
Matrix Matrix::operator*(const Matrix rhs) const{
	//multiplication
	//returns a new instance of the Matrix class after multiplying the matrices of the caller object and
	//the matrix passed to it as an argument.
	size_t rows,columns;
	rows=mat_rows;
	columns=rhs.mat_columns;
	//creating a new instance
	Matrix multi=Matrix(rows,columns,0.0);

	//logic to perform the matrix multiplication
	for(int i=0;i<rows;i++)
	{
		for(int k=0;k<columns;k++)
		{
			for(int j=0;j<mat_columns;j++)
			{
				multi.M[i][k]+=M[i][j]*rhs.M[j][k];
			}
		}	
	}
	return multi;
}

//unary negation
Matrix Matrix::operator-() const{
	//unary negation
	//returns a new instance of the Matrix class after negating the matrix of the caller object.
	size_t rows,columns;
	rows=mat_rows;
	columns=mat_columns;
	//creating a new instance
	Matrix negate=Matrix(rows,columns,0.0);

	//logic to perform negation of each element.
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			negate.M[i][j]=M[i][j]*(-1);
		}
	}
	return negate;
}

//extraction
istream& operator>>(istream& in,Matrix& mat)
{//extraction
//This operator reads elements from the input stream and populates the matrix row by row
	
	size_t rows,columns;
	rows=mat.mat_rows;
	columns=mat.mat_columns;
	float array[rows*columns]={};

	//reading the input.
	for(int i=0;i<(rows*columns);i++)
	{
		in>>array[i];
	}

	//populating the matrix row by row
	int num=0;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			mat.M[i][j]=*(array+num);
			num+=1;
		}
	}
	return in;
	//Matrix T=Matrix(rows,columns,array);
	
}
//insertion
ostream& operator<<(ostream& out,Matrix mat)
{//insertion
  //It prints the matrix row by row

	//logic to print the matrix row by row
	for(int i=0;i<mat.mat_rows;i++)
	{
		out<<mat.M[i][0];
		for(int j=1;j<mat.mat_columns;j++)
		{
			out<<" ";	
			out<<mat.M[i][j];	
		}
		out<<endl;
	}
	return out;

}
float* Matrix::operator[](int index)
{   //bracket operator
	//returns a float pointer to a row of the matrix at the specified index
	//this is the non const version
	return M[index];	
}
const float* Matrix::operator[](int index) const
{//bracket operator
	//returns a float pointer to a row of the matrix at the specified index
	//this is the const version
	return M[index];	
}

//desttructor
Matrix::~Matrix()
{//desttructor
	//it frees all the allocated memory from the heap when the object goes out of scope

	//delete operator to delete the allocated memory from the heap.
	delete[] M;
}


