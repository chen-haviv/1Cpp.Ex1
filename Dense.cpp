//
// Created by Chend on 12/18/2019.
//

#include "Dense.h"

/**
 * returns the weight of the given layer
 * @return
 */
const Matrix &Dense::getWeights() const
{
	return weights;
}

/**
 * default constructor, constructs a layer that will process a given unit and do activation
 * on it according to PDF
 * @param w the wight
 * @param bias the bias
 * @param activation
 */
Dense::Dense(const Matrix &w, const Matrix &bias, ActivationType activation) :
		weights(w), bias(bias), activation(activation)
{}

/**
 * returns the bias of the given layer
 * @return
 */
const Matrix &Dense::getBias() const
{
	return bias;
}

/**
 * activates the layer on the given matrix, in the following way: activation(w*m + b)
 * @param matrix the matrix to process
 * @return new matrix after processing
 */
Matrix Dense::operator()(const Matrix &matrix) const
{
	Matrix tmp = matrix;
	tmp = weights * matrix;
	tmp += bias;
	return activation(tmp);
}

