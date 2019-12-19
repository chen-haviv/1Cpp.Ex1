//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

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

	static void rectify(Matrix &matrix);

	static void softmaximize(Matrix &matrix);


public:
	explicit Activation(ActivationType actType);

	const ActivationType &getActivationType();

	void operator()(Matrix &m) const;


};

#endif //ACTIVATION_H
