#ifndef PROPERTY_H
#define PROPERTY_H


#include <string>

#include "../Tenants/Tenant.h"

class Property{

    protected:

        struct Tenants {
            Tenant ** tenants;
            double avg_tenant_budget;
            int num_tenants;
        };

        int prop_value;
        int prop_mortgage;
        int prop_mortgage_duration;
        Tenants prop_tenants;
        int prop_capacity;

        int get_budget_average(Tenants tenants);

    private:
        
        static const double prop_tax;
        static const char* const prop_locations[];
        std::string prop_location;

    public:

        Property();

        // ? create and clone - Virtual Functions
        Property(const Property &orig);
        Property & operator=(const Property &p);

        virtual Property * clone() const = 0;

        // TODO implement this in each
        virtual ~Property();

        double get_prop_value() const;
        char * get_prop_location() const;
        double get_prop_mortgage() const;
        double get_prop_tax() const;
        Tenants * get_prop_tenants() const;
        int get_prop_capacity() const;

        std::string toString() const;

        virtual std::string get_prop_type() const = 0;

};

#endif