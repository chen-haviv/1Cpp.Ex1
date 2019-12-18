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

class Activation{
private:
	ActivationType type;
	static Matrix rectify(const Matrix &matrix, Matrix &postActivation) ;
	static Matrix softmaximize(const Matrix &matrix, Matrix &postActivation) ;

	~Activation();

public:
	explicit Activation (ActivationType actType);

	const ActivationType& getActivationType();

	Matrix operator()(const Matrix &m);




};

#endif //ACTIVATION_H
