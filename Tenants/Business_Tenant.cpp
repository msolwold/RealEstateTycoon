/**
 * Business Tenant Class
 * 
 */

#include <string>
#include <iostream>

#include "Business_Tenant.h"

// *Constructors
Business_Tenant::Business_Tenant(){

    // 2000 - 10000
    budget = rand() % 8000 + 2000;
}

// *Helpers
void Business_Tenant::test_print() const {
    std::cout << "I am a business" << std::endl;
}

