// Matrix.h
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H
#define ADDITION_ERROR_MSG "Incompatible rows and columns in addition"
#define INCOMPATIBLE_FILE_TO_MATRIX "Number of numbers read does not match expected matrix size."
#define INVALID_INPUT "Invalid input from input file."
#define ERROR_INCOMPATIBLE_MATRIX_MULTIPLICATION "Incompatible matrices in multiplication attempt."
#define IMG_PROCESSED_MSG "Image processed:"
#define MLP_RESULT_MSG "Mlp result: "
#define PROBABILITY_MSG " at probability: "
/**
 * @struct MatrixDims
 * @brief Matrix dimensions container todo what is this???
 */
typedef struct MatrixDims
{
	int rows, cols;
} MatrixDims;

class Matrix
{
private:
	void getMaxProbNumber(float &probability, int &maxPobabilityNumber) const;
	int rows;
	int cols;
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

	float &operator()(int i, int j);// todo - return value should be & or not?? consts?

	const float& operator()(int i, int j) const;// todo - return value should be & or not?? consts?

	float &operator[](int i);

	const float& operator[] (int i) const;

	friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

	friend std::istream &operator>>(std::istream &in, Matrix &matrix);







// Insert Matrix class here...
};


#endif //MATRIX_H
