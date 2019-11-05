
#include "Player.h"
#include "../Properties/Property.h"
#include "PropertiesList.h"

class RandomEvent{

    private:

        Player * p;
        Property ** properties_forsale;

        int num_events;
        int num_hurricanes;
        int num_tornadoes;
        int num_earthquakes;
        int num_wildfires;
        int num_crashes;
        int num_gentrification;

        void execute_event(std::string loc, double damage);

    public:

        RandomEvent();
        RandomEvent(Player * p, Property ** forsale);
        RandomEvent(const RandomEvent &re);
        ~RandomEvent();

        bool event();

        void print_statistics();

        void print_events();
        void print_hurricane();
        void print_tornado();
        void print_earthquake();
        void print_wildfire();
        void print_crash();
        void print_gentrification();



};