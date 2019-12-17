//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

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

public:
	Activation (ActivationType actType);

	const ActivationType& geetActivationType();

	const float&operator()(std::istream& in);
};

#endif //ACTIVATION_H
