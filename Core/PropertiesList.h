#ifndef PROPERTIESLIST_H
#define PROPERTIESLIST_H

#include "../Properties/Property.h"

class PropertiesList {

    public:

        struct Node {
            Property * prop;
            Node *next;
        };

        PropertiesList();
        PropertiesList(const Property &p);


        PropertiesList(const PropertiesList &pl);
        PropertiesList & operator = (const PropertiesList &pl);
        ~PropertiesList();

        // *Helpers
        void print_properties();
        void print_head_tail();


        // *Accessors
        int get_length() const;
        Node * get_list() const;
        Property * get_property(int index) const;

        int get_num_apartments() const;
        int get_num_houses() const;
        int get_num_businesses() const;
        int get_total_properties() const;

        // *Mutators
        bool add_property(const Property &p);
        bool remove_property(int index);

    private:

        Node *head;
        Node *tail;

        int num_apartments;
        int num_houses;
        int num_businesses;
        int total_properties;

        // *Helpers
        Node * create_node(const Property &p);
        void delete_node(Node ** n);
        void update_prop_count(std::string s, int flag);

    

};

#endif