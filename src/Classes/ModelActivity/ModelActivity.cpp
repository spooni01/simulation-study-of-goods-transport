/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "ModelActivity.hpp"


/*
 *  Create process
 */
ModelActivity::ModelActivity(unsigned long trucks, double journeys) {
	this->trucks = new Store("Truck store", trucks);

	this->printStartOfMonth(journeys);
}


ModelActivity::~ModelActivity()
{

}


void ModelActivity::Behavior()
{

}


/*
 *  Write start of month in the STDOUT
 */
void ModelActivity::printStartOfMonth(double journeys) {
    std::cout   << "..................................................................\n"
                << "|                          MONTH START                           |\n"
                << "| Number of trucks: " << trucks->Capacity() << "\n"
                << "| Number of journeys: " << journeys << "\n"
                << "------------------------------------------------------------------\n"
                << std::endl;
}
