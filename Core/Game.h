#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"
#include "../Properties/Property.h"

// ? is this redundant?
#include "../Properties/House.h"
#include "../Properties/Apartment.h"
#include "../Properties/Business.h"

class Game {

    private:

        bool debug;
        std::string player_name;

        void build_game();

    public:

        Game();

        int run();

        void get_user_input();

        void test_House();
        void test_Apartment();
        void test_Business();
        void test_PropertiesList();
        void test_addRemove();

};

#endif