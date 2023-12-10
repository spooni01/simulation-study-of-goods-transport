/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "../UniformGenerator/UniformGenerator.hpp"

#ifndef IMS_TRUCK_HEADER_FILE
#define IMS_TRUCK_HEADER_FILE

class Truck : public Process
{
public:

	Truck(
		Store *trucks,
		Stat *statTruckJourneyForCargo,
		Stat *statTruckLoadingCargo,
		Stat *statTruckJourneyWithCargo,
		Stat *statTruckUnloadingCargo,
        Stat *statTruckFuelFull,
		Stat *statTruckFuelEmpty
	);

	void Behavior() override;

private:

    // Truck journey (minutes, percentage)
	const double TRUCK_JOURNEY_FOR_CUSTOMER = 64.0;
	const double TRUCK_JOURNEY_FOR_CUSTOMER_DEVIATION = 35.9; 

    // Truck loading (minutes, percentage)
	const double TRUCK_LOADING = 46.0; 
	const double TRUCK_LOADING_DEVIATION = 45.7;

    // Truck journey (minutes, percentage)
	const double TRUCK_JOURNEY = 840.0; 
	const double TRUCK_JOURNEY_DEVIATION = 71.4;

    // Truck unloading (minutes, percentage)
    const double TRUCK_UNLOADING = 28.0; 
	const double TRUCK_UNLOADING_DEVIATION = 50.0;

    // Truck pause time (minutes)
    const double TRUCK_PAUSE = 360.0;

	// Truck fuel full cargo statistics (l/100km, km/h, percentage)
	const double TRUCK_CONSUMPTION_FULL_CARGO = 34;
	const double TRUCK_DISTANCE_FULL_CARGO = 1123.0; 
	const double TRUCK_DISTANCE_FULL_CARGO_DEVIATION = 78.2;

	// Truck fuel empty cargo statistics (l/100km, kkm/h, percentage)
	const double TRUCK_CONSUMPTION_EMPTY_CARGO = 22;
	const double TRUCK_DISTANCE_EMPTY_CARGO = 85.0; 
	const double TRUCK_DISTANCE_EMPTY_CARGO_DEVIATION = 32.9;

    // Stats
	Store *trucks;
	Stat *statTruckJourneyForCargo;
	Stat *statTruckLoadingCargo;
	Stat *statTruckJourneyWithCargo;
	Stat *statTruckUnloadingCargo;
    Stat *statTruckFuelFull;
	Stat *statTruckFuelEmpty;

};

#endif
