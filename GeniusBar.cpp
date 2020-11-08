/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: GeniusBar.cpp, Project 1
 compliedwith = g++ -Wall -Wpedantic -Werror -g GeniusBar.cpp -o genius
 */
//  GeniusBar.cpp
#include "GeniusBar.hpp"
#include <iostream>
using namespace std;

GeniusBar::GeniusBar(){ //default constructor
    current_wait_time_ = 0;
    number_of_available_geniuses_ = TOTAL_NUMBER_OF_GENIUSES;
    number_of_customers_ = 0;
    Customer genius_bar_[MAX_NUMBER_OF_CUSTOMERS];
}

//pre: number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS
//post: add new_customer to genius_bar_ and increment current_wait_time_ by WAIT_TIME_INCREMENT
//return: true if number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS, false otherwise
bool GeniusBar::addWaitingCustomer(Customer& new_customer){
    if(number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS){
        genius_bar_[number_of_customers_] = new_customer;
        current_wait_time_ += WAIT_TIME_INCREMENT;
        new_customer.updateWaitTime(current_wait_time_);
        number_of_customers_ ++;
        return true;
    }
    return false;
}

//pre: (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)
//post: decrement number_of_customers_ and number_of_available_geniuses_
//return: true if (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0), false otherwise
bool GeniusBar::assignGeniusToCustomer(){
    if (number_of_customers_>0 && number_of_available_geniuses_>0) {
        number_of_customers_ --;
        number_of_available_geniuses_ --;
        return true;
    }
    return false;
}

//pre: number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES
//post: increment number_of_available_geniuses
//return: true if number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES, false otherwise
bool GeniusBar::releaseGenius(){
    if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
        number_of_available_geniuses_++;
        return true;
    }
    return false;
}

//pre: number_of_customers_ > 0
//post: increment the wait time of each customer on the genius_bar by WAIT_TIME_INCREMENT
//return: true if number_of_customers_ > 0, false otherwise
bool GeniusBar::updateCustomersWaitTime(){
    if (number_of_customers_>0){
        for (int i=0; i < number_of_customers_; i++) {
            genius_bar_[i].updateWaitTime(genius_bar_[i].getWaitTime() + WAIT_TIME_INCREMENT);
        }
        return true;
    }
    return false;
}
