// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#define ADDITION_ERROR_MSG "Incompatible rows and columns in addition"
#define INCOMPATIBLE_FILE_TO_MATRIX "Number of numbers read does not match "\
                                                     "expected matrix size."
#define INVALID_INPUT "Invalid input from input file."
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

	friend Matrix operator*(const float &c, const Matrix& a);

	Matrix operator+(const Matrix &b) const;

	Matrix &operator+=(const Matrix &b);

	const float& operator()(int i, int j) const;// todo - return value should be & or not?? consts?
	float& operator()(int i, int j);// todo - return value should be & or not?? consts?

	float& operator[](int i);
	const float& operator[](int i) const;

	friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

	friend std::istream &operator>>(std::istream &in, Matrix &matrix);

private:
	int rows;
	int cols;
	float*matrix; // pointer to the single dimensional array which is our matrix







// Insert Matrix class here...
};


#endif //MATRIX_H
