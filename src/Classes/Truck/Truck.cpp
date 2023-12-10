/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "Truck.hpp"


/*
 *  Set initial data
 */
Truck::Truck(Store *trucks, Stat *statTruckJourneyForCargo, Stat *statTruckLoadingCargo, Stat *statTruckJourneyWithCargo, Stat *statTruckUnloadingCargo, Stat *statTruckFuelFull, Stat *statTruckFuelEmpty) :
	trucks(trucks), statTruckJourneyForCargo(statTruckJourneyForCargo), statTruckLoadingCargo(statTruckLoadingCargo), statTruckJourneyWithCargo(statTruckJourneyWithCargo), statTruckUnloadingCargo(statTruckUnloadingCargo), statTruckFuelFull(statTruckFuelFull), statTruckFuelEmpty(statTruckFuelEmpty) {}


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

	// Empty cargo fuel stats
	double emptyCargoFuel = uniformGenerator.generate(TRUCK_DISTANCE_EMPTY_CARGO, TRUCK_DISTANCE_EMPTY_CARGO_DEVIATION);
	(*statTruckFuelEmpty)(emptyCargoFuel / 100.0 * TRUCK_CONSUMPTION_EMPTY_CARGO); 

	// Full cargo fuel stats
	double fullCargoFuel = uniformGenerator.generate(TRUCK_DISTANCE_FULL_CARGO, TRUCK_DISTANCE_FULL_CARGO_DEVIATION);
	(*statTruckFuelFull)(fullCargoFuel / 100.0 * TRUCK_CONSUMPTION_FULL_CARGO); 

	// Check if there was failure
	srand(time(NULL));
    if (rand() < (RAND_MAX * 0.023)) {
        Wait(TRUCK_REPAIR_TIME);
    }

	// Leave truck
	Leave(*trucks, 1);

}