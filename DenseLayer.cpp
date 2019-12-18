//
// Created by Chend on 12/18/2019.
//

#include "DenseLayer.h"

const Matrix &DenseLayer::getWeights() const
{
	return weights;
}

DenseLayer::DenseLayer(const Matrix &w, const Matrix &bias, ActivationType activation) :
		weights(w), bias(bias), activation(activation)
{}

const Matrix &DenseLayer::getBias() const
{
	return bias;
}

Matrix DenseLayer::operator()(Matrix &matrix) const
{
	Matrix res(weights.getRows(), weights.getCols());
	res = weights * matrix;
	res += bias;
	res = activation(res);
	return res;
}
