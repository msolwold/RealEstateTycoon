/**
 * Business Class
 * 
 */


#include <string>
#include <iostream>

#include "Business.h"

using namespace std;

// *Constructors
Business::Business(){

    prop_tenants = Tenants();

    // 1 - 5 rooms
    int num = rand() % 4 + 1;
    
    prop_tenants.tenants = create_tenants(num);
    prop_tenants.num_tenants = num;
    prop_tenants.avg_tenant_budget = get_budget_average(prop_tenants);

    // 400,000 - 600,000
    prop_value = (rand() % 200 + 400)*1000;

    // 1,200 - 4,000
    prop_mortgage = rand() % 2800 + 1200;

    // 100 - 500
    prop_mortgage_duration = prop_value / prop_mortgage;
    
    prop_capacity = num;
}

Business::Business(const Business &b){

    prop_tenants = Tenants();
    prop_tenants.num_tenants = b.prop_tenants.num_tenants;
    prop_tenants.avg_tenant_budget = b.prop_tenants.avg_tenant_budget;
    
    Tenant ** ten_array = new Tenant*[b.prop_capacity];


    for (int i = 0; i < b.prop_capacity; i++){
        ten_array[i] = b.prop_tenants.tenants[i];
    }

    prop_tenants.tenants = ten_array;

    prop_value = b.prop_value;
    prop_mortgage = b.prop_mortgage;
    prop_mortgage_duration = b.prop_mortgage_duration;
    prop_capacity = b.prop_capacity;

}

// *Virtual Copy Constructor
Business * Business::clone() const {
    return new Business(*this);
}

// * Helper
Tenant ** Business::create_tenants(int num){

    Tenant ** ten_array = new Tenant*[num];

    int i = 0;
    while (i < num){
        ten_array[i] = new Business_Tenant();
        i++;
    }

    return ten_array;
}

// *Accessors
string Business::get_prop_type() const {
    return "Business";
}

Business::~Business(){
    
}