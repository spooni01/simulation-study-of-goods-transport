/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#ifndef IMS_MONTH_TIMER_HEADER_FILE
#define IMS_MONTH_TIMER_HEADER_FILE

    #include "../ModelActivity/ModelActivity.hpp"


    class MonthTimer : public Event {
    public:

        explicit MonthTimer();
        void Behavior() override;

    private:

        const double TIME_MONTH = 30.0 * 24.0 * 60.0;   // Minutes

        void end();

    };


#endif