#ifndef PLAYER_H
#define PLAYER_H

#include "Property.h"

class Player {

    private:

        // ? Linked List of Properties
        struct Properties {
            Property prop;
            Properties *next;
        };


        Properties *head;
        Properties *tail;

        int num_apartments;
        int num_houses;
        int num_businesses;

    public:

        Player();

        // TODO Made Additional Constructors

        char * get_player_name() const;
        double get_player_bank() const;
        Property * get_player_properties() const;

        void add_prop();
        void add_bank(double amount);


        void remove_prop(int index);
        void sub_bank(double amount);


};

#endif