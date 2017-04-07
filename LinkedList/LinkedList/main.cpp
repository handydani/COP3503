//
//  main.cpp
//  LinkedList
//
//  Created by Daniela Isabel Travieso on 3/2/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//
#include "Header.h"
#include <iostream>
#include <string>
void LinkedList::printList()
{
    curr = head;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(curr-> data == "Free")
            {
                std::cout << curr-> data << " ";
                curr = curr-> next;
            }
            else {
                std::cout << curr-> data << " ";
                curr = curr-> next;
            }
        }
        std::cout << "\n";
    }
}
void LinkedList::remove(int input)
{
    
}
void LinkedList::get(int i)
{
    Node *curr = first;
    size_t count = 0;
    while (curr && count != i) {
        if(count == i){
            break;
        }
        curr = curr ->next;
    }
    if(count != i){
        
    }
}

void LinkedList::insert(int i, int input)
{
    if(head == NULL)
    {
        head = new Node(input);
        return;
    }
    head ->insert(value);
}

void Node::insert(int value)
{
    if (next == NULL)
    {
        next = new Node(value);
        return;
    }
    next->insert(value);
}

size_t LinkedList::size()
{
    return 0;
}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    
    LinkedList ll;
    ll.print();
    ll.add(2);
    ll.print();
    
    
    return 0;
}
