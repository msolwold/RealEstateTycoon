#ifndef HOUSE_H
#define HOUSE_H

#include "Property.h"
#include "../Tenants/Civilian_Tenant.h"

class House: public Property {

    private:

        Tenant ** create_tenants(int num);

    public: 
    
        House();
        House(const House &h);

        virtual ~House();

        virtual House * clone() const;

        virtual std::string get_prop_type() const;

};

#endif