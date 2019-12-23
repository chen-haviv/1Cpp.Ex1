#include <cmath>
#include "Activation.h"


Activation::Activation(ActivationType actType) : type(actType)
{}


/**
 * receives a matrix and processes it using the relevant activation function on it.
 * @param matrix the matrix to process by the activation function.
 * @return the matrix after processing it according to the requirements
 * programme
 */
Matrix Activation::operator()(const Matrix &matrix) const
{
	if (type == Relu)
	{
		return rectify(matrix);
	}
	else // Softmax can only work on vectors.
	{
		return softmaximize(matrix);
	}
}

/**
 * processes the matrix and returns it after activating softmax function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
Matrix Activation::softmaximize(const Matrix &matrix)
{
	Matrix tmp(matrix.getRows(), matrix.getCols());
	float sum = 0;
	for (int i = 0; i < matrix.getRows(); ++i)
	{
		sum += std::exp(matrix[i]);
		tmp[i] = std::exp(matrix[i]);
	}
	tmp = tmp * (1 / sum);
	return tmp;
}

/**
 * processes the matrix and returns it after activating ReLU function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
Matrix Activation::rectify(const Matrix &matrix)
{
	Matrix tmp(matrix.getRows(), matrix.getCols());
	for (int i = 0; i < matrix.getCols() * matrix.getRows(); ++i)
	{
		if (matrix[i] < 0)
		{
			tmp[i] = 0;
		}
		else
		{
			tmp[i] = matrix[i];
		}
	}
	return tmp;
}

/**
 * getter - sreturns this type's activation type
 * @return
 */
const ActivationType &Activation::getActivationType()
{
	return type;
}

