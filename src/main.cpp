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
    args.parse(argc, argv); 
    
    // Do simulation
    printStartOfSimulation(&args);

    for (int i = 1; i <= NUM_OF_SIMULATION_ATTEMPS; i++) {
        
        std::cout << "---------------------- SIMULATION NUMBER " << i << " -----------------------\n" << std::endl;
        Init(TIME_SIMULATION_START, TIME_SIMULATION_END);
        Run();

	}

    printEndOfSimulation();

    // Exit
    return 0;

}


/*
 *	Write start of simulation in the STDOUT
 */
void printStartOfSimulation(Arguments *args) {
    std::cout   << "------------------------------------------------------------------\n"
                << "|                      START OF SIMULATION                       |\n"
                << "------------------------------------------------------------------\n"
                << "| Number of trucks: " << args->trucks << "\n"
                << "| Number of journeys: " << args->journeys << "\n"
                << "------------------------------------------------------------------\n"
                << std::endl;
}

/*
 *	Write end of simulation in the STDOUT
 */
void printEndOfSimulation() {
    std::cout   << "------------------------------------------------------------------\n"
                << "|                      END OF SIMULATION                         |\n"
                << "------------------------------------------------------------------\n"
                << std::endl;
}