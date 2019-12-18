#include <istream>
#include "Activation.h"
#include <math.h>


Activation::Activation(ActivationType actType) : type(actType)
{}


/**
 * receives a matrix and processes it using the relevant activation function on it.
 * @param matrix the matrix to process by the activation function.
 * @return the matrix after processing it according to the requirements
 * todo see if I need to free recources here - if I need to use matrix argument later on in the
 * programme
 */
Matrix Activation::operator()(const Matrix &matrix) const
{
	Matrix postActivation(matrix.getRows(), matrix.getCols());
	if (type == Relu)
	{
		return rectify(matrix, postActivation);
	}
	else if (type == Softmax) // Softmax can only work on vectors.
	{
		return softmaximize(matrix, postActivation);
	}
}

/**
 * processes the matrix and returns it after activating softmax function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
Matrix Activation::softmaximize(const Matrix &matrix, Matrix &postActivation)
{
	float sum = 0;
	for (int i = 0; i < matrix.getRows(); ++i)
	{
		sum += exp(matrix[i]);
		postActivation[i] = exp(matrix[i]);
	}
	postActivation = postActivation * (1 / sum);
	return postActivation;
}
/**
 * processes the matrix and returns it after activating ReLU function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
Matrix Activation::rectify(const Matrix &matrix, Matrix &postActivation)
{
	for (int i = 0; i < matrix.getCols() * matrix.getRows(); ++i)
	{
		if (matrix[i] < 0)
		{
			postActivation[i] = 0;
		}
		else
		{
			postActivation[i] = matrix[i];
		}
	}
	return postActivation;
}
/**
 * getter - sreturns this type's activation type
 * @return
 */
const ActivationType &Activation::getActivationType()
{
	return type;
}
