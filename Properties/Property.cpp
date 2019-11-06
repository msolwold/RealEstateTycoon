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

    this->prop_location = prop_locations[rand() % 5];
}

// *Helpers
string Property::toString() const {

    string out = "This property is a ";
    out += get_prop_type();
    out += " with a value of ";
    out += to_string(prop_value);

    return out;
}

string Property::toString_detailed() const {

    string out = "This property is a ";
    out += get_prop_type();
    out += " with a value of ";
    out += to_string(prop_value);
    out += "\n";

    return out;
}

void Property::print_tenants(){
    
    for (int i = 0; i < prop_capacity; i++){
        std::cout << prop_tenants->tenants[i]->get_tenant_budget() << std::endl;
    }
}

// * Accessors
int Property::get_budget_average(const Property::Tenants &tenants){

    int totalBudget = 0, numTens = 0;
    for (int i = 0; i < tenants.num_tenants; i++){
        if (!tenants.tenants[i]->isEvicted()){
            totalBudget += tenants.tenants[i]->get_tenant_budget();
            numTens++;
        }
    }   

    return totalBudget/numTens;
}

std::string Property::get_prop_location() const {
    return this->prop_location;
}

int Property::get_prop_rent() const{
    return this->prop_rent;
}

double Property::get_prop_value() const {
    return this->prop_value;
}

Property::Tenants * Property::get_prop_tenants() {
    return prop_tenants;
}

int Property::get_prop_capacity() const {
    return this->prop_capacity;
}

double Property::get_prop_mortgage() const {
    return this->prop_mortgage;
}

// *Mutators
void Property::alter_prop_value(double damage){
    this->prop_value *= damage;
}

void Property::adjust_rent(int rent){
    this->prop_rent = rent;
}

// ! Destructor
Property::~Property(){

    for (int i = 0; i < prop_capacity; i ++){
        delete prop_tenants->tenants[i];
    }
    
    delete[] prop_tenants->tenants;
    prop_tenants->tenants = nullptr;
}