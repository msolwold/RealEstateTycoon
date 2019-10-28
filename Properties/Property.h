#ifndef PROPERTY_H
#define PROPERTY_H


#include <string>

#include "Tenant.h"

class Property{

    private:

        struct Tenants {
            Tenant * tenants;
            double avg_tenant_budget;
        };

        double prop_value;
        char *prop_location;
        double prop_mortgage;
        double prop_tax;
        Tenants * prop_tenants;
        int prop_capactity;


    public:


        Property();
        
        // TODO: Made additional Constructors

        double get_prop_value() const;
        char * get_prop_location() const;
        double get_prop_mortgage() const;
        double get_prop_tax() const;
        Tenants * get_prop_tenants() const;
        int get_prop_capacity() const;

};

#endif