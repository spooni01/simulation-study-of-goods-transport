/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include <getopt.h>

#ifndef IMS_ARGUMENTS_HEADER_FILE
#define IMS_ARGUMENTS_HEADER_FILE

    class Arguments {
    public:

        int trucks;                         // Stores number of trucks
        int journeys;                       // Stores number of journeys

        void parse(int argc, char *argv[]); // Function for parsing arguments
        void displayHelp();                 // Display help on STDOUT

    };

#endif