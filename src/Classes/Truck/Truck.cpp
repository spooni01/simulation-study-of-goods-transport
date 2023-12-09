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

	// Jorney to customer
	double truckJourneyToCustomer = uniformGenerator.generate(TRUCK_JOURNEY_FOR_CUSTOMER, TRUCK_JOURNEY_FOR_CUSTOMER_DEVIATION);
	(*statTruckJourneyForCargo)(truckJourneyToCustomer);
	Wait(truckJourneyToCustomer);

	// Loading truck
	double truckLoading = uniformGenerator.generate(TRUCK_LOADING, TRUCK_LOADING_DEVIATION);
	(*statTruckLoadingCargo)(truckLoading);
	Wait(truckLoading);

	// Truck journey
    double truckJourney = uniformGenerator.generate(TRUCK_JOURNEY, TRUCK_JOURNEY_DEVIATION);
	(*statTruckJourneyWithCargo)(truckJourney);
	Wait(truckJourney);

	// Unloading truck
    double truckUnloading = uniformGenerator.generate(TRUCK_UNLOADING, TRUCK_UNLOADING_DEVIATION);
	(*statTruckUnloadingCargo)(truckUnloading);
	Wait(truckUnloading);

	// Pause
    Wait(TRUCK_PAUSE);

	Leave(*trucks, 1);
	
}