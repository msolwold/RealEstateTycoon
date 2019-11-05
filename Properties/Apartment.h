#ifndef APARTMENT_H
#define APARTMENT_H

#include "Property.h"
#include "../Tenants/Civilian_Tenant.h"

class Apartment: public Property {

    private:

        Tenant ** create_tenants(int num);

    public: 
    
        Apartment();
        Apartment(const Apartment &a);

        virtual ~Apartment();

        virtual Apartment * clone() const;

        virtual std::string get_prop_type() const;

};

#endif