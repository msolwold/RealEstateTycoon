#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "PropertiesList.h"
#include "../Tenants/Tenant.h"
#include "../Properties/Property.h"

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

        void collect_rent();
        void failed_rent(bool arr[], Tenant ** tenants, int num);
        void adjust_rent(Property * prop, int budget, int failed);

        void pay_mortgages();

        void sell_properties();
        void buy_properties(Property ** properties_forsale);

        std::string get_player_name() const;
        double get_player_bank() const;
        PropertiesList * get_player_properties() const;

        void set_player_name(std::string name);

        void add_bank(double amount);

        void sub_bank(double amount);

};

#endif