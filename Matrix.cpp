#include <iostream>
#include <stdlib.h>
#include "Matrix.h"

class Matrix
{

public:
	// Constructors:
	/**
	 * non default constructor, creates a new matrix with rows rows and cols cols, initializes
	 * all of the matrix elements to 0.
	 * @param rows
	 * @param cols
	 */
	Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
	{
		matrix = (float *) malloc(sizeof(float) * rows * cols);
		for (float i: matrix)
		{
			i = 0;
		}
	}

	/**
	 * default constructor, uses constructor delegation in order to create a 1x1 matrix
	 */
	Matrix::Matrix() : Matrix(1, 1)
	{
	}
	/**
	 * creates a new matrix from the given matrix m, and copies every value from it to a new
	 * matrix with exactly the same rows and cols.
	 * @param m the matrix to copy coordinates from.
	 */
	Matrix::Matrix(const Matrix &m): Matrix(m.rows, m.cols)
	{
		for (int i = 0; i < rows*cols; i++){
			this.matrix[i] = m.matrix[i];
		}
	}


	// Destructor:
	Matrix::~Matrix();

	// Methods:
	int Matrix::getRows();

	int Matrix::getCols();

	void Matrix::vectorize();

	void Matrix::plainPrint();

	//Operators:
	Matrix &Matrix::operator=(const Matrix &b);

	Matrix Matrix::operator*(const Matrix &b) const;

	Matrix Matrix::operator*(const int &c) const;

	friend Matrix Matrix::operator*(const int &c, const Matrix &a);

	Matrix Matrix::operator+(const Matrix &b) const;

	Matrix &Matrix::operator+=(const Matrix &b);

	const int &
	Matrix::operator()(int i, int j) const;// todo - return value should be & or not?? consts?

	const int &Matrix::operator[](int i) const;

	friend std::ostream &Matrix::operator<<(std::ostream &out, const Matrix &matrix);

	friend std::istream &Matrix::operator>>(std::istream &in, Matrix &matrix);

private:
	int rows;
	int cols;
	float *matrix; // pointer to the single dimensional array which is our matrix


}