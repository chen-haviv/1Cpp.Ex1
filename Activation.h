//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#define BAD_ACTIVATION_MSG "Unsupported activation type."

#define ERROR_MSG "Error: "

#include "Matrix.h"


/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
	Relu,
	Softmax
};

/**
 * Activation of the layer, either a softmax or a relu function
 */
class Activation
{
private:
	ActivationType type;

/**
 * processes the matrix and returns it after activating ReLU function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
	static Matrix _rectify(const Matrix &matrix);

/**
 * processes the matrix and returns it after activating softmax function as described in the PDF.
 * @param matrix
 * @param postActivation
 * @return postActivation after processing
 */
	static Matrix _softmaximize(const Matrix &matrix);


public:
	/**
 * constructs an activation object with actType as activation
 * @param actType
 */
	explicit Activation(ActivationType actType);

/**
 * getter - sreturns this type's activation type
 * @return
 */
	const ActivationType &getActivationType();

/**
 * receives a matrix and processes it using the relevant activation function on it.
 * @param matrix the matrix to process by the activation function.
 * @return the matrix after processing it according to the requirements
 * programme
 */
	Matrix operator()(const Matrix &m) const;


};

#endif //ACTIVATION_H
