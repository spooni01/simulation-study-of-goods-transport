/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "MonthTimer.hpp"
using namespace std;


MonthTimer::MonthTimer() {
	
    Activate(Time + TIME_MONTH);

}


void MonthTimer::Behavior() {

	end();


}


void MonthTimer::end() {

	cout << "End of month: timer tick.\n";

}