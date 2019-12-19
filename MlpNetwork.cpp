//
// Created by Chend on 12/18/2019.
//

#include "MlpNetwork.h"
#include "Dense.h"

MlpNetwork::MlpNetwork(Matrix *wArray, Matrix *bArray) :
		weightArray(wArray), biasArray(bArray)
{}

/**
 * iterates over the indices of the last layer vector (expected to be 10x1 vector, which ONLY
 * contains numbers between 0 to 1) and extracts the number who's probability was maximal number
 * and it's probability.
 * @param m the 10x1 vector to analyze
 * @param probability the maximal robability
 * @param maxPobabilityNumber the number which has maximal probability for the inputted image
 */
Digit getMaxProbNumber(const Matrix &m, float &probability, int &maxPobabilityNumber)
{
	probability = 0;
	maxPobabilityNumber = 0;
	for (int k = 0; k < m.getRows(); ++k)
	{
		if (m[k] > probability)
		{
			probability = m[k];
			maxPobabilityNumber = k;
		}
	}
	return {(unsigned int) maxPobabilityNumber, probability};
}

Digit MlpNetwork::operator()(Matrix &m)
{
	//first layer
	Dense first(weightArray[0], biasArray[0], Relu);
	first(m);
	//second layer

	Dense second(weightArray[1], biasArray[1], Relu);
	second(m);
	//third layer

	Dense third(weightArray[2], biasArray[2], Relu);
	third(m);
	//fourth layer

	Dense fourth(weightArray[3], biasArray[3], Softmax);
	fourth(m);
	float prob;
	int number;
	Digit d = getMaxProbNumber(m, prob, number);

	return d;
}

