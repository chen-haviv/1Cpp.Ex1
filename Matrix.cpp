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
Matrix::Matrix(int rows, int cols) : dims({rows, cols})
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
Matrix::Matrix(const Matrix &m) : Matrix(m.dims.rows, m.dims.cols)
{
	matrix = new float[dims.rows * dims.cols];
	for (int i = 0; i < dims.rows * dims.cols; ++i)
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
}

// Methods:
/**
 *
 * @return the rows of a given matrix
 */
int Matrix::getRows() const
{
	return dims.rows;
}

/**
 *
 * @return the cols of a given matrix
 */
int Matrix::getCols() const
{
	return dims.cols;
}

/**
 * turns a matrix into a vector by making the rows the size of rows*cols and cols = 1
 */
Matrix &Matrix::vectorize()
{
	dims.rows = dims.rows * dims.cols;
	dims.cols = 1;
	return *this;
}

/**
 * Prints matrix elements, no return value. prints space after each element (incl. last element in
 * the row) prints newline after each row (incl. last row)
 */
void Matrix::plainPrint()
{
	for (int i = 0; i < dims.rows; ++i)
	{
		for (int j = 0; j < dims.cols; ++j)
		{
			std::cout << matrix[i * dims.cols + j];
			if (j != dims.cols - 1)
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
	delete[] matrix;
	dims.rows = b.dims.rows;
	dims.cols = b.dims.cols;
	matrix = new float[b.dims.rows * b.dims.cols];
	for (int i = 0; i < dims.rows * dims.cols; ++i)
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
Matrix Matrix::operator*(Matrix const &b) const
{
	if (dims.cols != b.dims.rows)
	{
		std::cerr << ERROR_MSG << ERROR_INCOMPATIBLE_MATRIX_MULTIPLICATION << std::endl;
		exit(1);
	}
	else
	{
		Matrix result(dims.rows, b.dims.cols);
		float sum = 0;
		for (int i = 0; i < dims.rows; ++i)
		{
			for (int j = 0; j < b.dims.cols; ++j)
			{
				for (int k = 0; k < dims.cols; ++k)
				{
					sum += matrix[i * dims.cols + k] * b.matrix[k * b.dims.cols + j];
				}
				result[i*b.dims.cols + j] = sum;
				sum = 0;
			}
		}
		return result;
	}
}

/**
 * multiplies the matrix by a scalar from the right side.
 * @param c the scalar by which we multiply the matrix.
 * @return the result of the multiplication.
 */
Matrix Matrix::operator*(const float &c) const
{
	Matrix res(dims.rows, dims.cols);
	for (int i = 0; i < dims.rows * dims.cols; ++i)
	{
		res.matrix[i] = matrix[i] * c;
	}
	return res;
}


/**
 * matrix multiplication by scalar from the left hand side.
 * @param c the scalar.
 * @param a the matrix.
 * @return the multiplication result.
 */
Matrix operator*(const float &c, const Matrix &a)
{
	Matrix res(a.dims.rows, a.dims.cols);
	for (int i = 0; i < a.dims.rows * a.dims.cols; ++i)
	{
		res.matrix[i] = a.matrix[i] * c;
	}
	return res;
}

/**
 * matrix addition as defined in the pdf.
 * @param b the right hand side matrix we wish to add.
 * @return the addition result.
 */
Matrix Matrix::operator+(const Matrix &b) const
{
	if (dims.rows != b.dims.rows || dims.cols != b.dims.cols)
	{
		std::cerr << ERROR_MSG << ADDITION_ERROR_MSG << std::endl;
		exit(1);

	}
	else
	{
		Matrix res(dims.rows, dims.cols);
		for (int i = 0; i < dims.rows * dims.cols; ++i)
		{
			res.matrix[i] = matrix[i] + b.matrix[i];
		}
		return res;
	}
}

/**
 * adds the given b matrix to the a matrix on the left hand side of the expression and assigns
 * the result to the left hand side of the expression.
 * @param b the matrix we wish to add to the left hand side.
 * @return makes the left hand side matrix the sum of the previous left hand side and the matrix
 * given as an argument.
 */
Matrix &Matrix::operator+=(const Matrix &b)
{
	if (dims.rows != b.dims.rows || dims.cols != b.dims.cols)
	{
		std::cerr << ERROR_MSG << ADDITION_ERROR_MSG << std::endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < dims.rows * dims.cols; ++i)
		{
			matrix[i] += b.matrix[i];
		}
		return *this;
	}
}

/**
 * access matrix coordinates using (i,j) notation, works on non const objects.
 * @param i
 * @param j
 * @return
 */
float &Matrix::operator()(int i, int j)
{
	return matrix[i * dims.cols + j];
}


/**
 * parenthesis indexing, returns the matrix coordinate in position (i,j). works on const objects.
 * @param i the row number.
 * @param j the col number.
 * @return the number found in the i'th row and j'th column.
 */
const float &Matrix::operator()(int i, int j) const
// consts?
{
	return matrix[i * dims.cols + j];
}


/** direct access to the matrix array, non const.
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
float &Matrix::operator[](int i)
{
	return matrix[i];
}

/** direct access to the matrix array, works on const matrices.
 * @param i the i'th element in the matrix array.
 * @return the value of the i'th element.
 */
const float &Matrix::operator[](int i) const
{
	return matrix[i];
}


/**
 *
 * @param out
 * @param matrix
 * @return
 */
std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
	std::cout << IMG_PROCESSED_MSG << std::endl;
	for (int i = 0; i < m.dims.rows; ++i)
	{
		for (int j = 0; j < m.dims.cols; ++j)
		{
			if (m(i, j) <= 0.1)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << "**";
			}
		}
		std::cout << std::endl;
	}
	return out;
}


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
std::istream &operator>>(std::istream &in, Matrix &m)
{
	in.seekg(0, std::istream::end);
	int length = in.tellg(); // goes to end of file to discover size, to ensure that compatible
	// with the matrix into which we write from the file
	in.seekg(0, std::istream::beg);
	if (length != m.dims.rows * m.dims.cols * sizeof(float)) // size should match matrix dimensions * float
	{
		std::cerr << ERROR_MSG << INCOMPATIBLE_FILE_TO_MATRIX << std::endl;
		exit(1);

	}
	float tempNum = 0;
	int i = 0;
	while (in.read(reinterpret_cast<char *>(&tempNum), sizeof(float)))
	{
		m.matrix[i] = tempNum;
		++i;
	}
	if (in.eof())
	{
		return in;
	}
	if (in.bad() || in.fail()) // if input file contains non float data
	{
		std::cerr << ERROR_MSG << INVALID_INPUT << std::endl;
		exit(1); // if something was wrong with reading from the file.
	}
	return in; // return the input stream as is because we might want to do something with it.
}

