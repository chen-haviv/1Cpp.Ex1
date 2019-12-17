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
	matrix = new float[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		matrix[i] = 0;
	}
}

/**
 * default constructor, uses constructor delegation in order to create a 1x1 matrix
 */
Matrix::Matrix() : Matrix(1, 1)
{
	matrix = new float[1];
	matrix[0] = 0;
}

/**
 * creates a new matrix from the given matrix m, and copies every value from it to a new
 * matrix with exactly the same rows and cols.
 * @param m the matrix to copy coordinates from.
 */
Matrix::Matrix(const Matrix &m) : Matrix(m.rows, m.cols)
{
	matrix = new float[rows * cols];
	for (int i = 0; i < rows * cols; ++i)
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
	delete[] matrix;
	delete this; // todo is this necessary?
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
			std::cout << matrix[i * rows + j];
			if (j != cols - 1)
			{
				std::cout << " "; // prints space between each coordinate
			}
		}
		std::cout << std::endl; // prints endl after end of each row
	}
}

//Operators:
/**
 * assigns all values of a given matrix to the matrix on the left hand side of the expression.
 * @param b the matrix we wish to assign
 * @return the object after deep copying
 */
Matrix &Matrix::operator=(const Matrix &b)
{
	if (this == &b)
	{
		return *this;
	}
	rows = b.rows;
	cols = b.cols;
	delete[] matrix;
	matrix = new float[b.rows * b.cols];
	for (int i = 0; i < rows * cols; ++i)
	{
		matrix[i] = b.matrix[i];
	}
	return *this;
}

/**
 * matrix multiplication as defined in the pdf
 * @param b the right hand side matrix.
 * @return the result of the multiplication.
 */
Matrix Matrix::operator*(const Matrix &b)
{
    for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i]; // todo
		}
	}
}

/**
 * multiplies the matrix by a scalar from the right side.
 * @param c the scalar by which we multiply the matrix.
 * @return the result of the multiplication.
 */
Matrix Matrix::operator*(const float &c)
{
    Matrix res(rows, cols);
	for (int i = 0; i < rows * cols; ++i)
	{
		res[i] = matrix[i] * c;
	}
	return res;
}


/**
 * matrix multiplication by scalar from the left hand side.
 * @param c the scalar.
 * @param a the matrix.
 * @return the multiplication result.
 */
Matrix operator*(const float &c, Matrix a)
{
    Matrix res(rows, cols);
    for (int i = 0; i < a.rows * a.cols; ++i)
	{
		res[i] = a.matrix[i] * c;
	}
	return res;
}

/**
 * matrix addition as defined in the pdf.
 * @param b the right hand side matrix we wish to add.
 * @return the addition result.
 */
Matrix Matrix::operator+(const Matrix &b)
{
	if (rows != b.rows || cols != b.cols)
	{
		std::cerr << ERROR_MSG << ADDITION_ERROR_MSG << std::endl;
	}
	else
	{
        Matrix res(rows, cols); // todo ask the metargel
        for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				res[i][j] = matrix[i * rows + j] + b.matrix[i * rows + j];
			}
		}
		return *res;
	}
}

/**
 * adds the given b matrix to the a matrix on the left hand side of the expression and assigns
 * the result to the left hand side of the expression.
 * @param b the matrix we wish to add to the left hand side.
 * @return makes the left hand side matrix the sum of the previous left hand side and the matrix
 * given as an argument.
 */
Matrix &Matrix::operator+=(const Matrix &b){
	if (rows != b.rows || cols != b.cols)
	{
		std::cerr << ERROR_MSG << ADDITION_ERROR_MSG << std::endl;
	}
	else
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				matrix[i * rows + j] += + b.matrix[i * rows + j];
			}
		}
		return *this;
	}
}

float& Matrix::operator()(int i, int j)
{
    return matrix[i * rows + j];
}



/**
 * parenthesis indexing, returns the matrix coordinate in position (i,j).
 * @param i the row number.
 * @param j the col number.
 * @return the number found in the i'th row and j'th column.
 */
const float& Matrix::operator()(int i, int j) const// todo - return value should be & or not??
// consts?
{
	return matrix[i * rows + j];
}


/** direct access to the matrix array
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
float& Matrix::operator[](int i) // todo see if this is what the poet meant
{
	return matrix[i];
}

/** direct access to the matrix array
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
const float& Matrix::operator[](int i) const // todo see if this is what the poet meant
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
{

}


/**
 *
 * @param in
 * @param matrix
 * @return
 */
friend std::istream &Matrix::operator>>(std::istream &in, Matrix &matrix);

