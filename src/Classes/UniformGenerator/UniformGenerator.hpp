/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include <random>
#include <chrono>

#ifndef IMS_UNIFORM_GENERATOR_HEADER_FILE
#define IMS_UNIFORM_GENERATOR_HEADER_FILE


    class UniformGenerator {
    public:

        UniformGenerator();
        double generate(double mid, double diff);

    private:

        std::default_random_engine generator;

    };


#endif 