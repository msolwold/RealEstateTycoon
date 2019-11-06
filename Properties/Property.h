#ifndef PROPERTY_H
#define PROPERTY_H


#include <string>

#include "../Tenants/Tenant.h"

class Property {

    public:

        struct Tenants {
            Tenant ** tenants;
            double avg_tenant_budget;
            int num_tenants;
        };

        Property();

        // ? create and clone - Virtual Functions
        Property(const Property &orig);
        Property & operator=(const Property &p);

        virtual Property * clone() const = 0;

        // TODO implement this in each
        virtual ~Property();

        double get_prop_value() const;
        std::string get_prop_location() const;
        double get_prop_mortgage() const;
        int get_prop_rent() const;
        double get_prop_tax() const;
        Tenants * get_prop_tenants();
        int get_prop_capacity() const;

        void alter_prop_value(double damage);
        void adjust_rent(int rent);

        std::string toString() const;
        std::string toString_detailed() const;
        void print_tenants();

        virtual std::string get_prop_type() const = 0;

    protected:

        int prop_value;
        int prop_mortgage;
        int prop_rent;
        int prop_mortgage_duration;
        Tenants * prop_tenants;
        int prop_capacity;

        int get_budget_average(const Tenants &tenants);

    private:
        
        static const double prop_tax;
        static const char* const prop_locations[];
        std::string prop_location;

};

#endif