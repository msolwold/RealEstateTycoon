/**
 * Civilian Tenant Class
 * 
 */

#include <string>
#include <iostream>

#include "Civilian_Tenant.h"

// *Constructors
Civilian_Tenant::Civilian_Tenant(){

    // 500 - 5000
    budget = rand() % 4500 + 500;
}

// *Helpers
void Civilian_Tenant::test_print() const {
    std::cout << "I am a civilian" << std::endl;
}