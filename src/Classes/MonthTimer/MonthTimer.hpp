/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#include "../ModelActivity/ModelActivity.hpp"

#ifndef IMS_MONTH_TIMER_HEADER_FILE
#define IMS_MONTH_TIMER_HEADER_FILE


    class MonthTimer : public Event {
    public:

        explicit MonthTimer(ModelActivity *modelActivity);
        void Behavior() override;

    private:

        ModelActivity *modelActivity;
        void writeEndOfMonth();

    };


#endif