#include <iostream>
#include <stdlib.h>
#include "Matrix.h"

#define ERROR_MSG "Error: "


// Constructors:
#define ASSIGNMENT_ERROR_MSG "Incompatible number of rows and columns in assignment"

/**
 * non default constructor, creates a new matrix with rows rows and cols cols, initializes
 * all of the matrix elements to 0.
 * @param rows
 * @param cols
 */
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
	matrix = (float *) malloc(sizeof(float) * rows * cols);
	for (int i = 0; i < rows * cols; i++)
	{
		i = 0;
	}
}

/**
 * default constructor, uses constructor delegation in order to create a 1x1 matrix
 */
Matrix::Matrix() : Matrix(1, 1)
{
	matrix = (float *) malloc(sizeof(float));
	matrix[0] = 0;
}

/**
 * creates a new matrix from the given matrix m, and copies every value from it to a new
 * matrix with exactly the same rows and cols.
 * @param m the matrix to copy coordinates from.
 */
Matrix::Matrix(const Matrix &m) : Matrix(m.rows, m.cols)
{
	for (int i = 0; i < rows * cols; i++)
	{
		matrix[i] = m.matrix[i];
	}
}


// Destructor:
/**
 * frees all of the allocations allocated in the matrix - mainly the array of floats which hold
 * the matrix values.
 */
Matrix::~Matrix()
{
	free(matrix);
	// free(this); // todo is this necessary?
}

// Methods:
/**
 *
 * @return the rows of a given matrix
 */
const int &Matrix::getRows()
{
	return rows;
}

/**
 *
 * @return the cols of a given matrix
 */
const int &Matrix::getCols()
{
	return cols;
}

/**
 * turns a matrix into a vector by making the rows the size of rows*cols and cols = 1
 */
void Matrix::vectorize()
{
	rows = rows * cols;
	cols = 1;
}

/**
 * Prints matrix elements, no return value. prints space after each element (incl. last element in
 * the row) prints newline after each row (incl. last row)
 */
void Matrix::plainPrint()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matrix[i * rows + j] << " ";
		}
		std::cout << std::endl;
	}
}

//Operators:
/**
 * assigns all values of a given matrix to the matrix on the left hand side of the expression.
 * @param b the matrix we wish to assign
 * @return todo see if need to return anything
 */
Matrix& Matrix::operator=(const Matrix &b)
{
	if (rows != b.rows || cols != b.cols)
	{
		std::cerr << ERROR_MSG << ASSIGNMENT_ERROR_MSG << std::endl;
	}
	else
	{
		for (int i = 0; i < rows * cols; i++)
		{
			matrix[i] = b.matrix[i];
		}
	}
}

/**
 * matrix multiplication as defined in the pdf
 * @param b the right hand side matrix.
 * @return the result of the multiplication.
 */
Matrix Matrix::operator*(const Matrix &b) const;

/**
 * multiplies the matrix by a scalar from the right side.
 * @param c the scalar by which we multiply the matrix.
 * @return the result of the multiplication.
 */
Matrix Matrix::operator*(const int &c) const;


/**
 * matrix multiplication by scalar from the left hand side.
 * @param c the scalar.
 * @param a the matrix.
 * @return the multiplication result.
 */
friend Matrix Matrix::operator*(const int &c, const Matrix &a);

/**
 * matrix addition as defined in the pdf.
 * @param b the right hand side matrix we wish to add.
 * @return the addition result.
 */
Matrix Matrix::operator+(const Matrix &b) const;

/**
 * adds the given b matrix to the a matrix on the left hand side of the expression and assigns
 * the result to the left hand side of the expression.
 * @param b the matrix we wish to add to the left hand side.
 * @return makes the left hand side matrix the sum of the previous left hand side and the matrix
 * given as an argument.
 */
Matrix &Matrix::operator+=(const Matrix &b);

/**
 * parenthesis indexing, returns the matrix coordinate in position (i,j).
 * @param i the row number.
 * @param j the col number.
 * @return the number found in the i'th row and j'th column.
 */
const float &Matrix::operator()(int i, int j) const// todo - return value should be & or not??
// consts?
{
	return matrix[i * rows + j];
}


/** direct access to the matrix array
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
const float &Matrix::operator[](int i) const // todo see if this is what the poet meant
{
	return matrix[i];
}

/**
 *
 * @param out
 * @param matrix
 * @return
 */
friend std::ostream &Matrix::operator<<(std::ostream &out, const Matrix &matrix);

/**
 *
 * @param in
 * @param matrix
 * @return
 */
friend std::istream &Matrix::operator>>(std::istream &in, Matrix &matrix);

