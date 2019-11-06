#ifndef TENANT_H
#define TENANT_H



class Tenant {

    protected: 

        double budget;

    private:
        
        int agreeability;
        bool evicted;
        
    public:

        Tenant();
        Tenant(const Tenant &t);
        Tenant & operator=(const Tenant &t);

        void evict();

        int get_tenant_agreeability();
        double get_tenant_budget();
        bool isEvicted();

        virtual void test_print() const;


};

#endif