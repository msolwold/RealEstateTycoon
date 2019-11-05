#ifndef BUSINESS_H
#define BUSINESS_H

#include "Property.h"
#include "../Tenants/Business_Tenant.h"

class Business: public Property {

    private:

        Tenant ** create_tenants(int num);

    public: 

        Business();
        Business(const Business &b);
        virtual ~Business();

        virtual Business * clone() const;
    
        virtual std::string get_prop_type() const;

};

#endif