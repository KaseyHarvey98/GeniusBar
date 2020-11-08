/*
 Author: Kasey Harvey
 Course: CSCI-235
 Assignment: Customer.cpp, Project 1
 compliedwith = g++ -Wall -Wpedantic -Werror -g Customer.cpp -o customer
 */
//  Customer.hpp
//  
//
//  Created by Kasey Harvey on 8/29/18.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>

#include <iostream>
using namespace std;
class Customer{
    
public:
    Customer();  //default constructor
    Customer(string name, string device = "unknown", int wait_time = 0);   //parameterized constructor
    
    //return: name_
    string getName();
    
    //return: defective_device_
    string getDevice();
    
    //return: wait_time_
    int getWaitTime();
    
    //post: wait_time_ = new_wait_time
    void updateWaitTime(int new_wait_time);
    
private:
    string name_;
    string defective_device_;
    int wait_time_;
    
}; // end Customer

#endif /* Customer_hpp */
