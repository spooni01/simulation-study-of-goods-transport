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
    statTruckFuelFull =         new Stat("Truck fuel: full cargo");
	statTruckFuelEmpty =		new Stat("Truck fuel: empty cargo");

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
	delete statTruckFuelFull;
	delete statTruckFuelEmpty;

}


/*
 *  Do simulation
 */
void ModelActivity::Behavior() {

	MonthTimer *monthTimer = new MonthTimer(this);

	// Do all journeys
	while (*journeysForSimulation > 0) {
		Enter(*trucks, 1);

		// If journey is done
		if(*journeysForSimulation == 0) {
			Leave(*trucks, 1);
			break;
		}

		*journeysForSimulation -= 1;

		// Do journey
		(new Truck(
			trucks,
			statTruckJourneyForCargo,
			statTruckLoadingCargo,
			statTruckJourneyWithCargo,
			statTruckUnloadingCargo,
			statTruckFuelFull,
			statTruckFuelEmpty
		))->Activate();

	}

	// Wait for trucks ends their journeys
	Enter(*trucks, trucks->Capacity());
	Leave(*trucks, trucks->Capacity());

	delete monthTimer;
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
    statTruckFuelFull->Output();
	statTruckFuelEmpty->Output();

}