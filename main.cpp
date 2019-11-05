/**
 * Author: Michael Solwold
 * Assignment: Lab4
 * Description: Real Estate Tycoon
 * Due Date: 10/25/19
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Core/Game.h"

using namespace std;

extern const bool debug(false);

bool run(){
    // TODO build run method

    return false;
}

void test_memleaks(Game g){

    /*
    cout << "Testing House" << endl;
    for (int i = 0; i < 10000000; i++){
        g.test_House();
    }

    cout << "Testing Apartment" << endl;
    for (int i = 0; i < 10000000; i++){
        g.test_Apartment();
    }

    cout << "Testing Business" << endl;
    for (int i = 0; i < 10000000; i++){
        g.test_Business();
    }
    
    cout << "Testing Business" << endl;
    for (int i = 0; i < 100000000; i++){
        g.test_PropertiesList();
    }*/

    
    for (int i = 0; i < 1000000; i++){
        g.test_addRemove();
    }
}

// TODO accept command line arguments to debug
int main(){

    srand (time(NULL));
    cout << "Hello World" << endl;
    
    Game g = Game();
    
    test_memleaks(g);
    
    return 0;

}