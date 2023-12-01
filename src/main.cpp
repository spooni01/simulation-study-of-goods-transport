/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "Libraries/main.hpp"

/*
 *	Main function
 */
int main() {

    UniformGenerator uniformDistribution;
    MonthTimer monthTimer;
    monthTimer.Behavior();

    std::cout << uniformDistribution.generate(10, 5) << std::endl;


    return 0;

}