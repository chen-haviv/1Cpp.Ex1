// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#define ADDITION_ERROR_MSG "Incompatible rows and columns in addition"
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

	Matrix(const Matrix &m);

	// Destructor:
	~Matrix();

	// Methods:
	const int& getRows();

	const int& getCols();

	void vectorize();

	void plainPrint();

	//Operators:
	Matrix &operator=(const Matrix &b);

	Matrix operator*(const Matrix &b);

	Matrix operator*(const float &c);

	friend Matrix operator*(const float &c, Matrix a);

	Matrix operator+(const Matrix &b);

	Matrix &operator+=(const Matrix &b);

	float operator()(int i, int j) const;// todo - return value should be & or not?? consts?

	float operator[](int i) const;

	friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);

	friend std::istream &operator>>(std::istream &in, Matrix &matrix);

private:
	int rows;
	int cols;
	float* matrix; // pointer to the single dimensional array which is our matrix







// Insert Matrix class here...
};


#endif //MATRIX_H
