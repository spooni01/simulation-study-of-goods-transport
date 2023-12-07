/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "Libraries/main.hpp"

/*
 *	Main function
 */
int main(int argc, char *argv[]) {

    Arguments args;
    UniformGenerator uniformDistribution;

    // Parse args
    args.parse(argc, argv);
    
    // Do simulation
    std::cout << "Number of trucks: " << args.trucks << "\n";
    std::cout << "Number of journeys: " << args.journeys << "\n";
    std::cout << uniformDistribution.generate(10, 5) << std::endl;

    return 0;

}