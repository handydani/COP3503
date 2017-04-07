//
//  Header.h
//  LinkedList
//
//  Created by Daniela Isabel Travieso on 3/2/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#ifndef pa2_h
#define pa2_h
#include <string>
#include <iostream> //necessary??

//Node information
class Node
{
    int i; //index
    std::string prgName; //name of program
public:
    Node(std::string name); //constructor
    Node *next;
    void setName(std::string prgName); //change name
    void setIndex(int i); //change index //necessary????
    std::string getName(void); //get the name of a program
    int getIndex(void); // get the index a program is at
};


//Memory management information
class LinkedList
{
public:
    LinkedList(void); //constructor // is void necessary???
    Node * head; //head is always null
    void add(int name, int prgSize, std::string arg); //add method
    void remove(int name); // remove method
    int getFragment(void); //searches for fragments
//    size_t size(); // might want to know size eventually
    void print(void); //print to console
};

bool isValidInput(double tempInput, int range);


#endif /* Header_h */
