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

/**
 * the Matrix class, supports various matrix operations as defined in PDF
 */
class Matrix
{
private:
	MatrixDims dims;
	float *matrix; // pointer to the single dimensional array which is our matrix



public:
	// Constructors:
/**
 * non default constructor, creates a new matrix with rows rows and cols cols, initializes
 * all of the matrix elements to 0.
 * @param rows
 * @param cols
 */
	Matrix(int rows, int cols);

/**
 * default constructor, uses constructor delegation in order to create a 1x1 matrix
 */
	Matrix();

/**
 * creates a new matrix from the given matrix m, and copies every value from it to a new
 * matrix with exactly the same rows and cols.
 * @param m the matrix to copy coordinates from.
 */
	Matrix(const Matrix &m);

	// Destructor:

	/**
 * frees all of the allocations allocated in the matrix - mainly the array of floats which hold
 * the matrix values.
 */
	~Matrix();

	// Methods:
/**
 *
 * @return the rows of a given matrix
 */
	int getRows() const;

/**
 *
 * @return the cols of a given matrix
 */
	int getCols() const;

/**
 * turns a matrix into a vector by making the rows the size of rows*cols and cols = 1
 */
	Matrix &vectorize();

/**
 * Prints matrix elements, no return value. prints space after each element (incl. last element in
 * the row) prints newline after each row (incl. last row)
 */
	void plainPrint() const;

	//Operators:
	/**
 * assigns all values of a given matrix to the matrix on the left hand side of the expression.
 * @param b the matrix we wish to assign
 * @return the object after deep copying
 */
	Matrix &operator=(const Matrix &b);

/**
 * matrix multiplication as defined in the pdf
 * @param b the right hand side matrix.
 * @return the result of the multiplication.
 */
	Matrix operator*(Matrix const &b) const;

/**
 * multiplies the matrix by a scalar from the right side.
 * @param c the scalar by which we multiply the matrix.
 * @return the result of the multiplication.
 */
	Matrix operator*(const float &c) const;

/**
 * matrix multiplication by scalar from the left hand side.
 * @param c the scalar.
 * @param a the matrix.
 * @return the multiplication result.
 */
	friend Matrix operator*(const float &c, const Matrix &a);

/**
 * matrix addition as defined in the pdf.
 * @param b the right hand side matrix we wish to add.
 * @return the addition result.
 */
	Matrix operator+(const Matrix &b) const;

/**
 * adds the given b matrix to the a matrix on the left hand side of the expression and assigns
 * the result to the left hand side of the expression.
 * @param b the matrix we wish to add to the left hand side.
 * @return makes the left hand side matrix the sum of the previous left hand side and the matrix
 * given as an argument.
 */
	Matrix &operator+=(const Matrix &b);

/**
 * access matrix coordinates using (i,j) notation, works on non const objects.
 * @param i
 * @param j
 * @return
 */
	float &operator()(int i, int j);

/**
 * parenthesis indexing, returns the matrix coordinate in position (i,j). works on const objects.
 * @param i the row number.
 * @param j the col number.
 * @return the number found in the i'th row and j'th column.
 */
	const float &operator()(int i, int j) const;

/** direct access to the matrix array, non const.
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
	float &operator[](int i);

/** direct access to the matrix array, works on const matrices.
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
	const float &operator[](int i) const;

/**
 *
 * @param out
 * @param matrix
 * @return
 */
	friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

/**
 * reads from the given input stream into our matrix.
 * assumes that the matrix field of m is empty! does not delete it if it has been previously
 * assigned!!!
 * discovers the size of the file, then checks to see if it's size is compatible with the
 * dimensions of the matrix, if not returns an error. if compatible, it reads the input file into
 * the given m.matrix array.
 * @param in the input stream, ideally a file opened with binary flag (binary file)
 * @param matrix the matrix which we read into
 * @return the input stream after it had finished reading.
 */
	friend std::istream &operator>>(std::istream &in, Matrix &matrix);







// Insert Matrix class here...
};


#endif //MATRIX_H
