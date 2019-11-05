/**
 * Linked List to hold properties
 * 
 * ? I think this is done, there are obviously bugs but its fully implemented
 * ? the num of units are managed by create and destroy node
 * ? The rest is fairly intuitive?
 */

#include <iostream>

#include "PropertiesList.h"

extern const bool debug;

// *Constructors
PropertiesList::PropertiesList(){
    head = tail = nullptr;

    num_apartments = 0;
    num_houses = 0;
    num_businesses = 0;
    total_properties = 0;
}

PropertiesList::PropertiesList(const Property &p){
    
    head = tail = create_node(p);

    num_apartments = 0;
    num_houses = 0;
    num_businesses = 0;
    total_properties = 0;
}

// *Copy Construstors
PropertiesList::PropertiesList(const PropertiesList &pl){
    
    // Copy empty list
    if (pl.get_total_properties() == 0){
        head = tail = nullptr;
        return;
    }

    Node * pl_list = pl.get_list();

    Node * new_node = create_node(*(pl_list->prop));
    head = new_node;

    while (pl_list->next != nullptr){

        pl_list = pl_list->next;
        new_node->next = create_node(*(pl_list->prop));
        new_node = new_node->next;
    }

    tail = new_node;
}

PropertiesList & PropertiesList::operator=(const PropertiesList &pl){
    
    if (&pl == this)
        return *this;

    // TODO - fix this
    // ! hack to avoid memory leaks
    if (head != nullptr)
        return *this;

    // Copy empty list
    if (pl.get_total_properties() == 0){
        head = tail = nullptr;
        return *this;
    }

    Node * pl_list = pl.get_list();

    Node * new_node = create_node(*(pl_list->prop));
    head = new_node;

    while (pl_list->next != nullptr){

        pl_list = pl_list->next;
        new_node->next = create_node(*(pl_list->prop));
        new_node = new_node->next;
    }

    tail = new_node;

    return *this;
}

// *Helpers
void PropertiesList::print_properties(){

    if (head == nullptr) {
        std::cout<< "You have no properties..." << std::endl;
        return;
    }

    PropertiesList::Node * tempHead = head;

    std::cout<< "Your Properties are..." << std::endl;

    int i = 1;
    while (tempHead != NULL) {

        std::cout << i++ << ". " << tempHead->prop->toString() << std::endl;
        tempHead = tempHead->next;
    }
}

void PropertiesList::print_head_tail(){
    if (this->head != NULL) std::cout << this->head << std::endl;
    if (this->head != NULL) std::cout << "tail" << this->tail->prop->toString() << std::endl;
}

// ! Report to M$
PropertiesList::Node * PropertiesList::create_node(const Property &p){

    Property * newP = p.clone();
    Node * n = new Node();

    n->prop = newP;
    n->next = nullptr;

    update_prop_count(p.get_prop_type(), 0);

    return n;
}

void PropertiesList::delete_node(Node ** n){

    update_prop_count(n[0]->prop->get_prop_type(), 1);

    delete n[0]->prop;
    n[0]->prop = nullptr;
    n[0]->next = nullptr;

    delete[] *n;
}

void PropertiesList::update_prop_count(std::string s, int flag){

    if (flag == 0){

        if (s.compare("House")) num_houses++;
        if (s.compare("Apartment")) num_apartments++;
        if (s.compare("Business")) num_businesses++;
        total_properties++;
    }

    if (flag == 1){

        if (s.compare("House")) num_houses--;
        if (s.compare("Apartment")) num_apartments--;
        if (s.compare("Business")) num_businesses--;
        total_properties--;
    }
}

// * Accessors
int PropertiesList::get_length() const{
    return this->total_properties;
}

PropertiesList::Node * PropertiesList::get_list() const{
    return this->head;
}

Property * PropertiesList::get_property(int index) const{
    
    Node * curr = head;

    int i = 0;
    while (i < index){
        curr = curr->next;
    }

    return curr->prop;
}

int PropertiesList::get_num_apartments() const{
    return this->num_apartments;
}

int PropertiesList::get_num_houses() const{
    return this->num_houses;
}

int PropertiesList::get_num_businesses() const{
    return this->num_businesses;
}

int PropertiesList::get_total_properties() const{
    return total_properties;
}

// *Mutators
bool PropertiesList::add_property(const Property &p){

    if (head == nullptr){

        this->head = this->tail = create_node(p);
        return true;
    }

    tail->next = create_node(p);
    tail = tail->next;

    return true;
}

bool PropertiesList::remove_property(int index){

    if (index > total_properties)
        return false;

    if (index == 1){

        std::cout << "Deleting the head..." << std::endl;

        PropertiesList::Node * tempHead = head;
        head = head->next;

        delete_node(&tempHead);

        return true;
    }

    Node * tempCurr = head;
    Node * delNode = head->next;

    int i = 1;
    while (i < index-1){
        tempCurr = tempCurr->next;
        delNode = delNode->next;
        i++;
    }

    if (index == total_properties){
        tempCurr->next = nullptr;
        tail = tempCurr;
    } else tempCurr->next = delNode->next;

    std::cout << "Deleting node at index " << index << std::endl;
    delete_node(&delNode);

    return true;
}

// ! Destructor
PropertiesList::~PropertiesList(){

    Node * tempCurr = head;
    Node * tempNext = NULL;

    if (head != nullptr) tempNext = head->next;

    while (tempNext != NULL){

        delete tempCurr->prop;
        tempCurr->prop = nullptr;
        tempCurr->next = nullptr;
        tempCurr = tempNext;
        tempNext = tempNext->next;
    }

    if (tempCurr != nullptr){
        delete tempCurr->prop;
        tempCurr->prop = nullptr;
        tempCurr->next = nullptr;
    }

    delete[] this->head;
    delete[] this->tail;
    delete this->head;
    head = tail = nullptr;
}



