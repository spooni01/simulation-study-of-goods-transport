/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "Truck.hpp"


/*
 *  Set initial data
 */
Truck::Truck(Store *trucks, Stat *statTruckJourneyForCargo, Stat *statTruckLoadingCargo, Stat *statTruckJourneyWithCargo, Stat *statTruckUnloadingCargo, Stat *statTruckFuel) :
	trucks(trucks), statTruckJourneyForCargo(statTruckJourneyForCargo), statTruckLoadingCargo(statTruckLoadingCargo), statTruckJourneyWithCargo(statTruckJourneyWithCargo), statTruckUnloadingCargo(statTruckUnloadingCargo), statTruckFuel(statTruckFuel) {}


/*
 *  Journey of truck
 */
void Truck::Behavior() {
    UniformGenerator ug; 

	double truckJourneyForCustomer = ug.generate(
		TRUCK_JOURNEY_FOR_CUSTOMER, TRUCK_JOURNEY_FOR_CUSTOMER_DEVIATION
	);
	(*statTruckJourneyForCargo)(truckJourneyForCustomer);
	Wait(truckJourneyForCustomer);

	double truckLoading = ug.generate(
		TRUCK_LOADING, TRUCK_LOADING_DEVIATION
	);
	(*statTruckLoadingCargo)(truckLoading);
	Wait(truckLoading);

    double truckJourney = ug.generate(
		TRUCK_JOURNEY, TRUCK_JOURNEY_DEVIATION
	);
	(*statTruckJourneyWithCargo)(truckJourney);
	Wait(truckJourney);

    double truckUnloading = ug.generate(
		TRUCK_UNLOADING, TRUCK_UNLOADING_DEVIATION
	);
	(*statTruckUnloadingCargo)(truckUnloading);
	Wait(truckUnloading);

    Wait(TRUCK_PAUSE);

	Leave(*trucks, 1);
}