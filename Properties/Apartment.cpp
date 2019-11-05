/**
 * Apartment Class
 * 
 */


#include <string>
#include <iostream>

#include "Apartment.h"

using namespace std;

// *Constructor
Apartment::Apartment(){

    prop_tenants = Tenants();

    // 4-10 rooms
    int num = rand() % 6 + 4;
    
    prop_tenants.tenants = create_tenants(num);
    prop_tenants.num_tenants = num;
    prop_tenants.avg_tenant_budget = get_budget_average(prop_tenants);

    // 300,000 - 500,000
    prop_value = (rand() % 200 + 300)*1000;

    // 1000 - 3,000
    prop_mortgage = rand() % 2000 + 1000;

    // 100 - 500
    prop_mortgage_duration = prop_value / prop_mortgage;
    
    prop_capacity = num;

}

Apartment::Apartment(const Apartment &a){

    prop_tenants = Tenants();
    prop_tenants.num_tenants = a.prop_tenants.num_tenants;
    prop_tenants.avg_tenant_budget = a.prop_tenants.avg_tenant_budget;
    
    Tenant ** ten_array = new Tenant*[a.prop_capacity];


    for (int i = 0; i < a.prop_capacity; i++){
        ten_array[i] = a.prop_tenants.tenants[i];
    }

    prop_tenants.tenants = ten_array;

    prop_value = a.prop_value;
    prop_mortgage = a.prop_mortgage;
    prop_mortgage_duration = a.prop_mortgage_duration;
    prop_capacity = a.prop_capacity;

}

// *Virtual Copy Constructor
Apartment * Apartment::clone() const {
    return new Apartment(*this);
}

// *Helper
Tenant ** Apartment::create_tenants(int num){

    Tenant ** ten_array = new Tenant*[num];

    int i = 0;
    while (i < num){

        ten_array[i] = new Civilian_Tenant();
        i++;
    }

    return ten_array;
}

// *Accessors
string Apartment::get_prop_type() const{
    return "Apartment";
}

Apartment::~Apartment(){
    
}