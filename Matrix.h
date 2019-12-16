// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
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

public:
	// Constructors:
	Matrix(int rows, int cols);

	Matrix();

	Matrix(Matrix &m);

	// Destructor:
	~Matrix();

	// Methods:
	int getRows();

	int getCols();

	void vectorize();

	void plainPrint();

	//Operators:
	Matrix &operator=(const Matrix &b);

	Matrix operator*(const Matrix &b) const;

	Matrix operator*(const int &c) const;

	friend Matrix operator*(const int &c, const Matrix &a);

	Matrix operator+(const Matrix &b) const;

	Matrix &operator+=(const Matrix &b);

	const int& operator()(int i, int j) const;// todo - return value should be & or not?? consts?

	const int& operator[](int i) const;

	friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);

	friend std::istream &operator>>(std::istream &in, Matrix &matrix);

private:
	int rows;
	int cols;
	int* matrix; // pointer to the single dimensional array which is our matrix







// Insert Matrix class here...
};


#endif //MATRIX_H
