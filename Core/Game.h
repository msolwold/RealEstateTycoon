#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"
#include "PropertiesList.h"
#include "../Properties/Property.h"
#include "RandomEvent.h"
#include "../Tenants/Tenant.h"

// ? is this redundant?
#include "../Properties/House.h"
#include "../Properties/Apartment.h"
#include "../Properties/Business.h"

class Game {

    private:

        bool debug;

        Player * p;
        Property ** properties_forsale;
        RandomEvent * re;

        int round;


        void build_game();
        Property ** generate_properties();
        void print_directions();

        void refill_forsale();


    public:

        Game();
        Game(const Game &g);
        ~Game();

        int run();


        void test_House();
        void test_Apartment();
        void test_Business();
        void test_PropertiesList();
        void test_addRemove();

};

#endif