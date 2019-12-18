//
// Created by Chend on 12/18/2019.
//

#ifndef DENSELAYER_H
#define DENSELAYER_H

#include "Matrix.h"
#include "Activation.h"


class DenseLayer
{
public:
	DenseLayer(const Matrix &w, const Matrix &bias, Activation activation);

	const Matrix& getWeights() const;

	const Matrix& getBias() const;

	ActivationType getActivation()
	{
		return activation.getActivationType(); // short function, inlined
	}

	~DenseLayer();



private:
	Matrix weights;
	Matrix bias;
	Activation activation;
};


#endif //CPP_EX1_DENSELAYER_H
