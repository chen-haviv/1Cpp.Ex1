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

Matrix Dense::operator()(const Matrix &matrix) const
{
	Matrix tmp = matrix;
	tmp = weights * matrix;
	tmp += bias;
	return activation(tmp);
}

