//
// Created by Chend on 12/18/2019.
//

#include "DenseLayer.h"

const Matrix &DenseLayer::getWeights() const
{
	return weights;
}

DenseLayer::DenseLayer(const Matrix &w, const Matrix &bias, Activation activation) :
		weights(w), bias(bias), activation(activation)
{}

const Matrix &DenseLayer::getBias() const
{
	return bias;
}
