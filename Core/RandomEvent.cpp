/**
 * Random Event Module
 * 
 */

#include <iostream>

#include "RandomEvent.h"

using namespace std;

RandomEvent::RandomEvent(){

    num_events = 0;
    num_hurricanes = 0;
    num_tornadoes = 0;
    num_earthquakes = 0;
    num_wildfires = 0;
    num_crashes = 0;
    num_gentrification = 0;
}

RandomEvent::RandomEvent(Player * p, Property ** forsale){

    num_events = 0;
    num_hurricanes = 0;
    num_tornadoes = 0;
    num_earthquakes = 0;
    num_wildfires = 0;
    num_crashes = 0;
    num_gentrification = 0;

    this->p = p;
    this->properties_forsale = forsale;
}

bool RandomEvent::event(){

    cout << "Executing random event..." << endl;

    // 1 - 6
    int event = rand() % 5 + 1;

    switch (event) {

        case 1:
            print_hurricane();
            execute_event("SW", .5);
            num_events++;
            num_hurricanes++;
            break;
        case 2:
            print_tornado();
            execute_event("MW", .7);
            num_events++;
            num_tornadoes++;
            break;
        case 3:
            print_earthquake();
            execute_event("NW", .9);
            num_events++;
            num_earthquakes++;
            break;
        case 4:
            print_wildfire();
            execute_event("SW", .75);
            num_events++;
            num_wildfires++;
            break;
        case 5:
            print_crash();
            execute_event("ALL", .7);
            num_events++;
            num_crashes++;
            break;
        case 6:
            print_gentrification();
            execute_event("ALL", 1.2);
            num_events++;
            num_gentrification++;
            break;
        default: return false;
    }

    return true;
}

void RandomEvent::execute_event(string target, double damage){

    PropertiesList * pl = this->p->get_player_properties();
    PropertiesList::Node * curr = pl->get_list();

    for (int i = 0; i < pl->get_length(); i++){

        if (target == "ALL" || curr->prop->get_prop_location() == target)
            curr->prop->alter_prop_value(damage);

        curr = curr->next;
    }

    for (int i = 0; i < 9; i++){

        if (target == "ALL" || properties_forsale[i]->get_prop_location() == target)
            properties_forsale[i]->alter_prop_value(damage);
    }
}

void RandomEvent::print_events(){

    cout << "Printing all events..." << endl << endl;
    print_hurricane();
    print_tornado();
    print_earthquake();
    print_wildfire();
    print_crash();
    print_gentrification();
}

void RandomEvent::print_hurricane(){

    cout << "Event: Hurricane" << endl;
    cout << "Impacts: Southeast" << endl;
    cout << "Action: Decrease Property Value by 50%" << endl;
}

void RandomEvent::print_tornado(){

    cout << "Event: Tornado" << endl;
    cout << "Impacts: Midwest" << endl;
    cout << "Action: Decrease Property Value by 30%" << endl;
}

void RandomEvent::print_earthquake(){

    cout << "Event: Earthquake" << endl;
    cout << "Impacts: Northwest" << endl;
    cout << "Action: Decrease Property Value by 10%" << endl;
}

void RandomEvent::print_wildfire(){

    cout << "Event: Wildfire" << endl;
    cout << "Impacts: Southwest" << endl;
    cout << "Action: Decrease Property Value by 25%" << endl;
}

void RandomEvent::print_crash(){

    cout << "Event: Stock Market Crash" << endl;
    cout << "Impacts: All Properties" << endl;
    cout << "Action: Decrease Property Value by 30%" << endl;
}

void RandomEvent::print_gentrification(){

    cout << "Event: Big Business moves in to the area" << endl;
    cout << "Impacts: Random Area" << endl;
    cout << "Action: Increase Property Value by 20%" << endl;
}


RandomEvent::~RandomEvent(){

    delete properties_forsale;
    delete p;
}