//
//  pa2.h
//  PA2
//
//  Created by Daniela Isabel Travieso on 2/27/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>


struct node{
    std::string song;
    std::string artist;
    node * next;
};


class LinkedList
{
private:
    node * head;
    int listLength;
    
public:
    LinkedList();
    
    bool insertNode( node * newNode, int position );
    
    bool removeNode( int position );
    
    void printList();
    
    ~LinkedList();
};

#endif /* pa2_h */
