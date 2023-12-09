/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include <iostream>
#include <simlib.h>
#include <getopt.h>
#include <random>
#include <chrono>

/*
 *  STATIC VARIABLES
 */
static const int NUM_OF_SIMULATION_ATTEMPS  = 3;
static const double TIME_SIMULATION_START   = 0.0;
static const double TIME_SIMULATION_END     = 43200.0;
static const double JOURNEY_DEVIATION       = 35.9;

/*
 *  Header files
 */
#include "../Classes/Arguments/Arguments.hpp"
#include "../Classes/ModelActivity/ModelActivity.hpp"
#include "../Classes/MonthTimer/MonthTimer.hpp"
#include "../Classes/Truck/Truck.hpp"
#include "../Classes/UniformGenerator/UniformGenerator.hpp"


/*
 *  Program files
 */
#include "../Classes/Arguments/Arguments.cpp"
#include "../Classes/ModelActivity/ModelActivity.cpp"
#include "../Classes/MonthTimer/MonthTimer.cpp"
#include "../Classes/Truck/Truck.cpp"
#include "../Classes/UniformGenerator/UniformGenerator.cpp"


/*
 *  Functins in main.cpp
 */
int main(int argc, char *argv[]);
void printStartOfSimulation(Arguments *args);
void printEndOfSimulation();