#ifndef CITIZENTENANT_H
#define CITIZENTENANT_H

#include "Tenant.h"

class Citizen_Tenant: public Tenant {

    private:


    public: 
    
        double get_tenant_budget();
            
        void set_tenant_budget(double budget);

};

#endif