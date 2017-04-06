//
//  Header.h
//  pa3
//
//  Created by Travieso,Daniela I on 3/31/17.
//  Copyright © 2017 Travieso,Daniela I. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>

class StackClass
{

  private:

  public:
    StackClass();
    void push(std::string token);
    std::string pop();
    bool isEmpty();
    bool contains(string data);
    int size();
    void printStack();
    bool exists();
    string top();
    int size;

    typedef struct Node{
      std:string info;
      Node *next;
      bool isFree; //edit later
    }* nodePointer;

    nodePointer head;
    nodePointer curr;
    nodePointer temp;


}

StackClass readFile(std::string name);

Stack::Stack()
{
  head = NULL;
  curr = NULL;
  temp = NULL;
  size = 0;
}
void StackClass::push(std::string token)
{
    nodePointer nPtr = new Node;
    n->next = NULL;
    n->info = token;

    if(head != NULL)
    {
        curr = head;

        while(curr->next!=NULL)
        {
            curr = curr->next;
        }

        curr->next = n;
    }
    else
    {
        head = n;
    }
    size++;
}
std::string StackClass::pop()
{
    std::string popped;
    curr = head;




    size--;
}




#endif /* Header_h */
