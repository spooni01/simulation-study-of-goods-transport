/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "UniformGenerator.hpp"


/*
 *	Generates a random number within a specified range by uniform distribution
 */
double UniformGenerator::generate(double mid, double diff) {

	return Uniform(mid - (diff / 100.0 * mid), mid + (diff / 100.0 * mid));

}
