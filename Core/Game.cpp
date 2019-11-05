/**
 * Driver for the game
 * 
 */

#include <iostream>

#include "Game.h"
#include "PropertiesList.h"

using namespace std;

Game::Game(){
    
    cout << "Creating new game..." << endl << endl;

    build_game();

}

int Game::run(){

    return 1;
}

void Game::build_game(){

    cout << "Please enter your name (Press Enter for no name): ";
    getline(cin, this->player_name);
}

void Game::get_user_input(){

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