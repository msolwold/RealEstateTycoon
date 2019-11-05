#ifndef CIVILIANTENANT_H
#define CIVILIANTENANT_H

#include "Tenant.h"

class Civilian_Tenant: public Tenant {

    private:


    public: 
    
        Civilian_Tenant();

        virtual void test_print() const;
            
};

#endif