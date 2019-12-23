//
// Created by Chend on 12/18/2019.
//

#ifndef DENSELAYER_H
#define DENSELAYER_H

#include "Matrix.h"
#include "Activation.h"

/**
 * the dense layer as defined in PDF
 */
class Dense
{
public:
	/**
	 * default constructor, constructs a layer that will process a given unit and do activation
	 * on it according to PDF
	 * @param w the wight
	 * @param bias the bias
	 * @param activation
	 */
	Dense(const Matrix &w, const Matrix &bias, ActivationType activation);

/**
 * returns the weight of the given layer
 * @return
 */
	const Matrix &getWeights() const;

/**
 * returns the bias of the given layer
 * @return
 */
	const Matrix &getBias() const;

/**
 * returns the type of activation in this layer, either softmax or relu
 * @return
 */
	ActivationType getActivation()
	{
		return activation.getActivationType(); // short function, inlined
	}

/**
 * activates the layer on the given matrix, in the following way: activation(w*m + b)
 * @param matrix the matrix to process
 * @return new matrix after processing
 */
	Matrix operator()(const Matrix &matrix) const;


private:
	Matrix weights;
	Matrix bias;
	Activation activation;
};


#endif //CPP_EX1_DENSELAYER_H
