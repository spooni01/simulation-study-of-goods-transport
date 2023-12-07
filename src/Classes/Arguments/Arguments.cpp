/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "Arguments.hpp"


/*
 *	Parse arguments
 */
void Arguments::parse(int argc, char *argv[]) {
        
    // Set arguments
    struct option long_options[] = {
        {"trucks", required_argument, 0, 't'},
        {"journeys", required_argument, 0, 'j'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    // Loop through arguments
    int opt;
    while ((opt = getopt_long(argc, argv, "t:j:h", long_options, NULL)) != -1) {

        switch (opt) {

            case 't':
                this->trucks = std::atoi(optarg);
                break;

            case 'j':
                this->journeys = std::atoi(optarg);
                break;

            case 'h':
                this->displayHelp();
                break;

            case '?':
            default:
                throw std::invalid_argument("Unknown option");

        }

    }
}


/*
 *	Write help on STDOUT
 */
void Arguments::displayHelp() {

    std::cout << "Usage:\n"
              << "-t/--trucks <number_of_trucks> -j/--journeys <number_of_journeys> [-h/--help]\n";
    exit(0);

}
