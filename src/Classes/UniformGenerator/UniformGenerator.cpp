/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "UniformGenerator.hpp"


/*
 *	Set seed
 */
UniformGenerator::UniformGenerator() {

    // Seed with current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);

}


/*
 *	Generates a random number within a specified range by uniform distribution
 */
double UniformGenerator::generate(double mid, double diff) {
        
	std::uniform_real_distribution<double> distribution(mid - (diff / 100.0 * mid), mid + (diff / 100.0 * mid));
    return distribution(generator);

}

