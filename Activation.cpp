#include <istream>
#include "Activation.h"


Activation::Activation(ActivationType actType)
{
	type = actType;
}

const float &Activation::operator()(std::istream &in)
{
	return in;
}

const ActivationType &Activation::geetActivationType()
{
	return <#initializer#>;
}
