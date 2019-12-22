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

class Activation
{
private:
	ActivationType type;

	static Matrix rectify(const Matrix &matrix);

	static Matrix softmaximize(const Matrix &matrix);


public:
	explicit Activation(ActivationType actType);

	const ActivationType &getActivationType();

	Matrix operator()(const Matrix &m) const;


};

#endif //ACTIVATION_H
