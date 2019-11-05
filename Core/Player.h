#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../Core/PropertiesList.h"

class Player {

    private:

        std::string name;
        double bank;
        PropertiesList * prop_list;

    public:

        Player();
        Player(std::string name);

        Player(const Player &p);
        Player & operator = (const Player &p);
        ~Player();

        std::string get_player_name() const;
        double get_player_bank() const;
        struct Properties * get_player_properties() const;

        void set_player_name(std::string name);

        void add_bank(double amount);

        void sub_bank(double amount);

};

#endif