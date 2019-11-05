

#include "Player.h"


Player::Player(){

    name = "";
    bank = 500000;
    PropertiesList * prop_list = new PropertiesList();
}

Player::Player(std::string n){

    name = n;
    bank = 500000;
    PropertiesList * prop_list = new PropertiesList();
}

Player::Player(const Player &p){

    name = p.name;
    bank = p.bank;
    PropertiesList * prop_list = new PropertiesList(*p.prop_list);
}

Player & Player::operator=(const Player &p){

    if (&p == this)
        return *this;

    name = p.name;
    bank = p.bank;

    if (prop_list != NULL)
        delete prop_list;
    
    PropertiesList * prop_list = new PropertiesList(*p.prop_list);

    return *this;
    
} 

Player::~Player(){
    delete prop_list;
}

// * Accessors

std::string Player::get_player_name() const {
    return name;
}

double Player::get_player_bank() const {
    return bank;
}


// * Mutators
void Player::set_player_name(std::string n){
    name = n;
}

void Player::add_bank(double amount){
    bank += amount;
}

