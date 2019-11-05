/**
 * Description: Property Class
 * Children: Apartment, House, Business
 * 
 */

#include <iostream>

#include "Property.h"

using namespace std;

const char* const Property::prop_locations[]  = {"SE", "NE", "MW", "SW", "NW"};
const double Property::prop_tax = 1.5;

Property::Property(){
    prop_location = prop_locations[rand() % 5];
}

// *Helpers
string Property::toString() const {

    string out = "This property is a ";
    out += get_prop_type();
    out += " and has ";
    out += to_string(prop_tenants.num_tenants);
    out += " tenants ";

    return out;
}

// * Accessors
int Property::get_budget_average(Tenants tenants){

    int totalBudget = 0;
    for (int i = 0; i < tenants.num_tenants; i++){
        totalBudget += tenants.tenants[i]->get_tenant_budget();
    }   

    return totalBudget/(tenants.num_tenants);
}

// ! Destructor
Property::~Property(){

    for (int i = 0; i < prop_capacity; i ++){
        delete prop_tenants.tenants[i];
    }
    
    delete[] prop_tenants.tenants;
    prop_tenants.tenants = nullptr;
}