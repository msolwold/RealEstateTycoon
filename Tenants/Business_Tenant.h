#ifndef BUSINESSTENANT_H
#define BUSINESSTENANT_H

#include "Tenant.h"

class Business_Tenant: public Tenant {

    private:
         
         

    public: 

        Business_Tenant();
    
        double get_tenant_budget();
        
        void set_tenant_budget(double budget);


};

#endif