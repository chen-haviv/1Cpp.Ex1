//
// Created by Chend on 12/18/2019.
//

#ifndef DENSELAYER_H
#define DENSELAYER_H

#include "Matrix.h"
#include "Activation.h"


class Dense
{
public:
	Dense(const Matrix &w, const Matrix &bias, ActivationType activation);

	const Matrix& getWeights() const;

	const Matrix& getBias() const;

	ActivationType getActivation()
	{
		return activation.getActivationType(); // short function, inlined
	}

	void operator()(Matrix& matrix) const;




private:
	Matrix weights;
	Matrix bias;
	Activation activation;
};


#endif //CPP_EX1_DENSELAYER_H
