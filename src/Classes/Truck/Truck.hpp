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
        Stat *statTruckFuel
	);

	void Behavior() override;

private:

    // Truck journey (minutes, percentage)
	const double TRUCK_JOURNEY_FOR_CUSTOMER = 64.0;
	const double TRUCK_JOURNEY_FOR_CUSTOMER_DEVIATION = 35.9; 

    // Truck loading (minutes, percentage)
	const double TRUCK_LOADING = 46.0; // in minutes
	const double TRUCK_LOADING_DEVIATION = 45.7; // in percentage

    // Truck journey (minutes, percentage)
	const double TRUCK_JOURNEY = 840.0; // in minutes
	const double TRUCK_JOURNEY_DEVIATION = 71.4; // in perentage

    // Truck unloading (minutes, percentage)
    const double TRUCK_UNLOADING = 28.0; // in km
	const double TRUCK_UNLOADING_DEVIATION = 50.0; // in perentage

    // Truck pause time (minutes)
    const double TRUCK_PAUSE = 360.0;

    // Stats
	Store *trucks;
	Stat *statTruckJourneyForCargo;
	Stat *statTruckLoadingCargo;
	Stat *statTruckJourneyWithCargo;
	Stat *statTruckUnloadingCargo;
    Stat *statTruckFuel;

};

#endif
