//
// Created by Chend on 12/18/2019.
//

#include "Dense.h"

const Matrix &Dense::getWeights() const
{
	return weights;
}

Dense::Dense(const Matrix &w, const Matrix &bias, ActivationType activation) :
		weights(w), bias(bias), activation(activation)
{}

const Matrix &Dense::getBias() const
{
	return bias;
}

void Dense::operator()(Matrix &matrix) const
{
	matrix = weights * matrix;
	matrix += bias;
	activation(matrix);
}

