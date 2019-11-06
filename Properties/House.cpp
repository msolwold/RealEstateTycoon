/**
 * House Class
 * 
 */

#include <string>
#include <iostream>

#include "House.h"

using namespace std;

// *Constructors
House::House(){

    prop_tenants = new Tenants();
    prop_tenants->tenants = create_tenants(1);
    prop_tenants->avg_tenant_budget = 
        prop_tenants->tenants[0]->get_tenant_budget();
    prop_tenants->num_tenants = 1;

    // 200,000 - 400,000
    prop_value = (rand() % 200 + 200)*1000;

    // 800 - 2,000
    prop_mortgage = rand() % 1200 + 800;

    // 100 - 570
    prop_mortgage_duration = prop_value / prop_mortgage;
    
    prop_capacity = 1;
    prop_rent = prop_tenants->avg_tenant_budget * .8;
}

House::House(const House &h){

    prop_tenants = new Tenants();
    prop_tenants->num_tenants = h.prop_tenants->num_tenants;
    prop_tenants->avg_tenant_budget = h.prop_tenants->avg_tenant_budget;
    
    Tenant ** ten_array = new Tenant*[h.prop_capacity];


    for (int i = 0; i < h.prop_capacity; i++){
        ten_array[i] = h.prop_tenants->tenants[i];
    }

    prop_tenants->tenants = ten_array;

    prop_value = h.prop_value;
    prop_mortgage = h.prop_mortgage;
    prop_mortgage_duration = h.prop_mortgage_duration;
    prop_capacity = h.prop_capacity;
    prop_rent = h.prop_rent;

}

// *Virtual Copy Constructor
House * House::clone() const {
    return new House(*this);
}

// *Helpers
Tenant ** House::create_tenants(int num){

    Tenant ** ten_array = new Tenant*[num];

    ten_array[0] = new Civilian_Tenant();

    return ten_array;
}

// *Accessors
string House::get_prop_type() const{
    return "House";
}

House::~House(){
    
}