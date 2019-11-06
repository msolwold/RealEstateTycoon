
#include <iostream>
#include "Player.h"


Player::Player(){

    name = "Player";
    bank = 500000;
    prop_list = new PropertiesList();
}

Player::Player(std::string n){

    name = n;
    bank = 500000;
    prop_list = new PropertiesList();
}

Player::Player(const Player &p){

    name = p.name;
    bank = p.bank;
    prop_list = new PropertiesList(*p.prop_list);
}

Player & Player::operator=(const Player &p){

    if (&p == this)
        return *this;

    name = p.name;
    bank = p.bank;

    if (prop_list != NULL)
        delete prop_list;
    
    prop_list = new PropertiesList(*p.prop_list);

    return *this;
    
}

// * Helpers
void Player::collect_rent(){

    PropertiesList::Node * curr = prop_list->get_list();

    std::cout << "Collecting rent from the following properties: " << std::endl;
    prop_list->print_properties();

    while (curr != NULL){

        bool rent[curr->prop->get_prop_capacity()];
        int failed = 0;

        Property::Tenants * prop_tenants = curr->prop->get_prop_tenants();
        Tenant ** tenants = prop_tenants->tenants;

        for (int i = 0; i < curr->prop->get_prop_capacity(); i++){
            
            if (tenants[i]->get_tenant_budget() >= curr->prop->get_prop_rent()){
                
                std::cout << "Collecting rent from tenant " << i+1 << std::endl;
                add_bank(curr->prop->get_prop_rent());
                rent[i] = true;
            }

            else { 
                
                std::cout << "Tenant " << i+1 << " has a insufficient budget of ";
                std::cout << tenants[i]->get_tenant_budget() << std::endl;
                rent[i] = false;
                failed++;
            }
        }

        if (failed > 0) failed_rent(rent, tenants, curr->prop->get_prop_capacity());
        adjust_rent(curr->prop, prop_tenants->avg_tenant_budget, failed);

        curr = curr->next;
    }

    std::cout << "Done Collecting Rent..." << std::endl << std::endl;
}

void Player::failed_rent(bool rent[], Tenant ** tenants, int num){

    std::string response;
    
    std::cout << "The following spaces failed to pay rent: " << std::endl;
    for (int i = 0; i < num; i++){

        if (!rent[i]){
            std::cout << i+1 << ". with a budget of " << tenants[i]->get_tenant_budget();
            std::cout << std::endl;
        }
    }

    std::cout << "Would you like to evict any tenants? (1 for yes, 0 for no): ";
    std::cin >> response;

    if (response == "1"){

        while (true){
            std::cout << "Enter the number of the tenant you would like to evict (Press Enter to end): ";
            std::getline(std::cin, response);

            if (response == "") break;

            if (tenants[std::stoi(response)]->get_tenant_agreeability() > 2){
                
                std::cout << "Tenant " << response << " is evicted" << std::endl;
                tenants[std::stoi(response)]->evict();
            }

            else std::cout << "This tenant refuses to leave..." << std::endl;
        }
    }

}

void Player::adjust_rent(Property * prop, int budget, int failed){

    std::string response;
    
    std::cout << failed << " tenants failed to pay the rent of ";
    std::cout << prop->get_prop_rent() << std::endl;
    std::cout << "The average budget of this property is " << budget << std::endl;
    std::cout << "Would you like to adjust the rent? (1 for yes, 0 for no): ";

    std::cin >> response;

    if (response == "1"){

        std::cout << "What would you like the new rent to be?: ";
        std::cin >> response;

        prop->adjust_rent(std::stoi(response));
    }
}

void Player::pay_mortgages(){

    PropertiesList::Node * curr = prop_list->get_list();

    while (curr != NULL){
        bank -= curr->prop->get_prop_mortgage();
        curr = curr->next;
    }
}

void Player::sell_properties(){

    std::string response;
    std::cout << "Would you like to sell any properties? (Press 1 for yes, 0 for no): ";
    std::cin >> response;

    if (response == "1"){

        while (true){

            prop_list->print_properties();

            std::cout << "Enter the number of the property that you would like to sell";
            std::cout << "(Press Enter to exit): ";
            std::cin >> response;

            if (response == "") break;

            try {
                bank += prop_list->get_property(std::stoi(response))->get_prop_value();
                prop_list->remove_property(std::stoi(response));
            }
            catch (int e){
                std::cout << "Invalid Entry..." << std::endl;
            }
        }
    }
}

void Player::buy_properties(Property ** properties_forsale){

    std::cout << std::endl;

    while (true){

        std::cout << "The properties you can buy are: " << std::endl << std::endl;

        for (int i = 0; i < 9; i ++) {
            if (properties_forsale[i] != NULL) 
                std::cout << i+1 << ". " << properties_forsale[i]->toString() << std::endl;
        }

        std::string response;
        std::cout << "Enter the number of the property that you would like to purchase(Press Enter to exit): ";
        std::getline(std::cin, response);

        if (response == "") break;

        if (properties_forsale[std::stoi(response)-1]->get_prop_value() > bank)
            std::cout << "You do not have enough money for that..." << std::endl;
    
        else{
            
            try{
                prop_list->add_property(*properties_forsale[std::stoi(response)-1]);
                bank-=properties_forsale[std::stoi(response)-1]->get_prop_value();
                delete properties_forsale[std::stoi(response)-1];
                properties_forsale[std::stoi(response)-1] = NULL;
            }
            catch (int e){
                std::cout << "Invalid Input..." << std::endl;
            }
        }
    }
}

// * Accessors

std::string Player::get_player_name() const {
    return name;
}

double Player::get_player_bank() const {
    return bank;
}

PropertiesList * Player::get_player_properties() const {
    return this->prop_list;
}

// * Mutators
void Player::set_player_name(std::string n){
    name = n;
}

void Player::add_bank(double amount){
    bank += amount;
}

void Player::sub_bank(double amount){
    bank -= amount;
}


Player::~Player(){

    delete prop_list;
}