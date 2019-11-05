/**
 * Tenant Parent Class
 * 
 */


#include <string>
#include <iostream>

#include "Tenant.h"

// *Constructors
Tenant::Tenant(){

    agreeability = std::rand() % 4 + 1;
}

Tenant::Tenant(const Tenant &t){

    agreeability = t.agreeability;
    budget = t.budget;
}

Tenant & Tenant::operator=(const Tenant &t){

    if (&t == this){
        return *this;
    }

    agreeability = t.agreeability;
    budget = t.budget;

    return *this;
}

// *Helpers
void Tenant::test_print() const {
    std::cout << "I'm a Tenant" << std::endl;
}

// *Accessors
double Tenant::get_tenant_budget(){
    return budget;
}

int Tenant::get_tenant_agreeability(){
    return agreeability;
}