/* * * * * * * * * * * * * * * * 
 *  Project:    IMS project    *
 *  Author:     Adam Ližičiar  *
 * * * * * * * * * * * * * * * */

#ifndef IMS_MODEL_ACTIVITY_HEADER_FILE
#define IMS_MODEL_ACTIVITY_HEADER_FILE


    class ModelActivity : public Process {
    public:
        
        ModelActivity(unsigned long trucks, double journeys);
        ~ModelActivity() override;      
        void Behavior() override;

    private:

        Store *trucks;
        unsigned long *journeys;
        void printStartOfMonth(double journeys);
        void printEndOfMonth();

    };


#endif