//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include <istream>

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784},
								  {64,  128},
								  {20,  64},
								  {10,  20}};
const MatrixDims biasDims[] = {{128, 1},
							   {64,  1},
							   {20,  1},
							   {10,  1}};
/**
 * the mlpNetwork which runs the entire show.
 */
class MlpNetwork
{
private:
	Matrix *weightArray;
	Matrix *biasArray;

	/**
 * iterates over the indices of the last layer vector (expected to be 10x1 vector, which ONLY
 * contains numbers between 0 to 1) and extracts the number who's probability was maximal number
 * and it's probability.
 * @param m the 10x1 vector to analyze
 * @param probability the maximal robability
 * @param maxPobabilityNumber the number which has maximal probability for the inputted image
 */
	Digit _getMaxProbNumber(const Matrix &m, float &probability, int &maxPobabilityNumber);


public:
	/**
 * constructs mlpNetwork with the given array pointers
 * @param wArray
 * @param bArray
 */
	MlpNetwork(Matrix wArray[4], Matrix bArray[4]);

/**
 * activates all of the layers on param m and returns a Digit struct with the probability and the
 * most probable number assessed by the neural network from the analyzed picture.
 * @param m the picture to analyze
 * @return Digit holding the most probable number and it's probability.
 */
	Digit operator()(const Matrix &m);
};


#endif // MLPNETWORK_H
