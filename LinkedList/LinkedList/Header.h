//
//  Header.h
//  LinkedList
//
//  Created by Daniela Isabel Travieso on 3/2/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string>
using namespace std;

struct Node
{
    std::string data;
    Node* next;
    bool isEmpty;
};

class LinkedList
{

private:
    Node* head;
    Node* curr;
    
    
public:
    LinkedList();
    void addNode(std::string data);
    void printList();
};

void LinkedList::addNode(std::string data)
{
    Node* p = new Node;
    p->next = NULL;
    p->data = data;
    
    if(head != NULL)
    {
        curr = head;
        
        while(curr-> next != NULL)
        {
            curr = curr-> next;
        }
        curr-> next = p;
    }
    else
    {
        head = p;
    }
}

LinkedList::LinkedList()
{
    head = NULL;
    curr = NULL;
}




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
#endif /* Header_h */
