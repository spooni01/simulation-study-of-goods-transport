/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "MonthTimer.hpp"


/*
 *  Set timer
 */
MonthTimer::MonthTimer(ModelActivity *modelActivity) : modelActivity(modelActivity) {

	Activate(Time + (TIME_SIMULATION_END - TIME_SIMULATION_START));

}


/*
 *  End month
 */
void MonthTimer::Behavior() {

	this->writeEndOfMonth();
	delete modelActivity;

}


/*
 *  Write end month message on STDOUT
 */
void MonthTimer::writeEndOfMonth() {

	std::cout << "Month timer elapsed!\n";

}