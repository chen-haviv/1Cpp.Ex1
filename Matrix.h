// Matrix.h
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H
#define ADDITION_ERROR_MSG "Incompatible rows and columns in addition"
#define INCOMPATIBLE_FILE_TO_MATRIX "Number of numbers read does not match expected matrix size."
#define INVALID_INPUT "Invalid input from input file."
#define ERROR_INCOMPATIBLE_MATRIX_MULTIPLICATION "Incompatible matrices in multiplication attempt."
#define ERROR_MSG "Error: "
#define BAD_COORDINATES_MSG "Impermissible attempt to acces matrix coordinates."
#define INVALID_MATRIX_CREATION "Invalid attempt at creating a matrix: impermissible row size or"\
                           " columns size; A matrix can only have positive integers rows and "\
                           "columns."
#define FAILED_ALLOC "Unsuccessful allocation attempt."

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
	int rows, cols;
} MatrixDims;

class Matrix
{
private:
	MatrixDims dims;
	float *matrix; // pointer to the single dimensional array which is our matrix



public:
	// Constructors:
	Matrix(int rows, int cols);

	Matrix();

	Matrix(const Matrix &m);

	// Destructor:
	~Matrix();

	// Methods:
	int getRows() const;

	int getCols() const;

	Matrix &vectorize();

	void plainPrint();

	//Operators:
	Matrix &operator=(const Matrix &b);

	Matrix operator*(Matrix const &b) const;

	Matrix operator*(const float &c) const;

	friend Matrix operator*(const float &c, const Matrix &a);

	Matrix operator+(const Matrix &b) const;

	Matrix &operator+=(const Matrix &b);

	float &operator()(int i, int j);

	const float &operator()(int i, int j) const;

	float &operator[](int i);

	const float &operator[](int i) const;

	friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

	friend std::istream &operator>>(std::istream &in, Matrix &matrix);







// Insert Matrix class here...
};


#endif //MATRIX_H
