#ifndef BUSINESSTENANT_H
#define BUSINESSTENANT_H

#include "Tenant.h"

class Business_Tenant: public Tenant {

    private:
         

    public: 
    
        Business_Tenant();

        virtual void test_print() const;


};

#endif