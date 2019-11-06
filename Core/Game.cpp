/**
 * Driver for the game
 * 
 */

#include <iostream>

#include "Game.h"

using namespace std;

Game::Game(){
    
    cout << "Creating new game..." << endl << endl;

    round = 0;

    build_game();

}

Game::Game(const Game &g){
    this->p = g.p;
    this->properties_forsale = g.properties_forsale;
    this->re = g.re;
}

int Game::run(){

    print_directions();

    cout << "Purchase Properties you would like to start the game with:" << endl;
    p->buy_properties(properties_forsale);

    while (p->get_player_bank() > 0 && p->get_player_bank() < 1000000){
        
        cout << "Your Current Balance is: " << p->get_player_bank() << endl;

        p->collect_rent();
        p->pay_mortgages();
        if (p->get_player_bank() <= 0 || p->get_player_bank() >= 1000000) break;
        re->event();
        p->sell_properties();
        cout << endl;
        p->buy_properties(properties_forsale);
        refill_forsale();

    }

    return 1;
}

void Game::build_game(){

    cout << "Please enter your name (Press Enter for no name): ";

    string player_name = "";
    getline(cin, player_name);

    if (player_name == "") this->p = new Player();
    else this->p = new Player(player_name);

    this->properties_forsale = generate_properties();

    this->re = new RandomEvent(p, properties_forsale);    
}

// *Helpers
Property ** Game::generate_properties(){
    
    Property ** properties = new Property*[9];
    int i = 0;

    // Houses
    for (int j = i*3; j < 3*(i+1); j++){
        properties[j] = new House();
    }
    i++;

    // Apartments
    for (int j = i*3; j < 3*(i+1); j++){
        properties[j] = new Apartment();
    }
    i++;

    // Businesses
    for (int j = i*3; j < 3*(i+1); j++){
        properties[j] = new Business();
    } 

    return properties;
}

void Game::print_directions(){

}

void Game::refill_forsale(){

    int i = 0;

    // Houses
    for (int j = i*3; j < 3*(i+1); j++){
        if (properties_forsale[j] == NULL) 
            properties_forsale[j] = new House();
    }
    i++;

    // Apartments
    for (int j = i*3; j < 3*(i+1); j++){
        if (properties_forsale[j] == NULL) 
            properties_forsale[j] = new Apartment();
    }
    i++;

    // Businesses
    for (int j = i*3; j < 3*(i+1); j++){
        if (properties_forsale[j] == NULL) 
            properties_forsale[j] = new Business();
    } 
}

void Game::test_House(){

    House h = House();
}

void Game::test_Apartment(){

    Apartment a = Apartment();
}

void Game::test_Business(){

    Business b = Business();
}

void Game::test_PropertiesList(){

    PropertiesList b = PropertiesList();
}

void Game::test_addRemove(){

    PropertiesList * pl = new PropertiesList();

    cout << "Num Properties: " << pl->get_total_properties() << endl;
    cout << "Num Houses: " << pl->get_num_businesses() << endl;
    cout << "Num Apartments: " << pl->get_num_apartments() << endl;
    cout << "Num Businesses: " << pl->get_num_businesses() << endl;

    House * h = new House();
    Apartment * a = new Apartment();
    Business * b = new Business();

    cout << "h is a " << h->get_prop_type() << endl;
    cout << "a is a " << a->get_prop_type() << endl;
    cout << "b is a " << b->get_prop_type() << endl;


    pl->add_property(*h);
    cout << "Num Properties: " << pl->get_total_properties() << endl;

    pl->add_property(*a);
    cout << "Num Properties: " << pl->get_total_properties() << endl;

    pl->add_property(*b);
    cout << "Num Properties: " << pl->get_total_properties() << endl;

    pl->print_properties();
    pl->print_head_tail();

    pl->remove_property(3);
    cout << "Num Properties: " << pl->get_total_properties() << endl;

    pl->print_properties();
    pl->print_head_tail();

    pl->remove_property(2);
    cout << "Num Properties: " << pl->get_total_properties() << endl;

    pl->print_properties();
    pl->print_head_tail();

    pl->remove_property(1);
    cout << "Num Properties: " << pl->get_total_properties() << endl;

    pl->print_properties();    
}

Game::~Game(){

    cout << "Deleting player..." << endl;
    delete p;
    
    cout << "Deleting for sale properties..." << endl;

    for (int i = 0; i < 9; i++){
        delete properties_forsale[i];
    }

    cout << "Deleteing event..." << endl;
    delete re;
}