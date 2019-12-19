#include <istream>
#include "Activation.h"
#include <cmath>


Activation::Activation(ActivationType actType) : type(actType)
{}


/**
 * receives a matrix and processes it using the relevant activation function on it.
 * @param matrix the matrix to process by the activation function.
 * @return the matrix after processing it according to the requirements
 * programme
 */
void Activation::operator()(Matrix &matrix) const
{
	if (type == Relu)
	{
		rectify(matrix);
	}
	else if (type == Softmax) // Softmax can only work on vectors.
	{
		softmaximize(matrix);
	}
}

/**
 * processes the matrix and returns it after activating softmax function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
void Activation::softmaximize(Matrix &matrix)
{
	float sum = 0;
	for (int i = 0; i < matrix.getRows(); ++i)
	{
		sum += exp(matrix[i]);
		matrix[i] = exp(matrix[i]);
	}
	matrix = matrix * (1 / sum);
}
/**
 * processes the matrix and returns it after activating ReLU function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
void Activation::rectify(Matrix &matrix)
{
	for (int i = 0; i < matrix.getCols() * matrix.getRows(); ++i)
	{
		if (matrix[i] < 0)
		{
			matrix[i] = 0;

		}

	}
}
/**
 * getter - sreturns this type's activation type
 * @return
 */
const ActivationType &Activation::getActivationType()
{
	return type;
}

