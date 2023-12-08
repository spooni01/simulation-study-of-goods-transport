/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "ModelActivity.hpp"
#include "../UniformGenerator/UniformGenerator.hpp"


/*
 *  Create process
 */
ModelActivity::ModelActivity(unsigned long trucks, double numOfJurneys) {

	this->trucks = new Store("Truck store", trucks);
	*journeysForSimulation = static_cast<long unsigned>(numOfJurneys);

    // Set statistics
    statTruckJourneyForCargo =  new Stat("Truck time: journey for cargo");
    statTruckLoadingCargo =     new Stat("Truck time: loading cargo");
    statTruckJourneyWithCargo = new Stat("Truck time: journey with cargo");
    statTruckUnloadingCargo =   new Stat("Truck time: unloading cargo");
    statTruckFuel =             new Stat("Truck fuel");

	this->printStartOfMonth();

}


/*
 *  Clean after process
 */
ModelActivity::~ModelActivity() {

	this->printEndOfMonth();

	delete journeysForSimulation;
    delete statTruckJourneyForCargo;
	delete statTruckLoadingCargo;
	delete statTruckJourneyWithCargo;
	delete statTruckUnloadingCargo;
	delete statTruckFuel;

}


/*
 *  Do simulation
 */
void ModelActivity::Behavior() {
	
}


/*
 *  Write start of month in the STDOUT
 */
void ModelActivity::printStartOfMonth() {
    std::cout   << "..................................................................\n"
                << "|                          MONTH START                           |\n"
                << "| Number of trucks: " << trucks->Capacity() << "\n"
                << "| Number of journeys: " << *journeysForSimulation << "\n"
                << "..................................................................\n"
                << std::endl;
}


/*
 *  Write end of month with statistics in the STDOUT
 */
void ModelActivity::printEndOfMonth() {

    std::cout   << "..................................................................\n"
                << "|                           MONTH END                            |\n"
                << "| Time: " << Time << "\n"
                << "| Number of journeys left: " << *journeysForSimulation << "\n"
                << "..................................................................\n"
                << std::endl;

	trucks->Output();
	statTruckJourneyForCargo->Output();
	statTruckLoadingCargo->Output();
	statTruckJourneyWithCargo->Output();
	statTruckUnloadingCargo->Output();
    statTruckFuel->Output();

	std::cout << "////////////////////////////////////////////////////////////\n";

}