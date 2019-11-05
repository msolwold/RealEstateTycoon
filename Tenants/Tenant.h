#ifndef TENANT_H
#define TENANT_H



class Tenant {

    protected: 

        double budget;

    private:
        
        int agreeability;
        
    public:

        Tenant();
        Tenant(const Tenant &t);
        Tenant & operator=(const Tenant &t);


        int get_tenant_agreeability();
        double get_tenant_budget();

        virtual void test_print() const;


};

#endif