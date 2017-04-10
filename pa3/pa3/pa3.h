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

class Stack
{
  int depth;
  public:
    Stack();
    void push()
    {
        ++depth;
    }
    int pop()
    {
        return --depth;
    }
    int depthStack()
    {
        return depth;
    }
};
Stack::Stack()
{
    this->depth = 0;
}
class DepthStack
{
	std::vector<int> vect;
public:
    DepthStack()
    {

    }

	void push(int data)
	{
		vect.push_back(data);
	}
	void pop()
	{
		vect.pop_back();
	}
	int top()
	{
		int data = vect.back();
		return data;
	}
	int size()
	{
		return vect.size();
	}

};

class Inventory
{
  std::vector<std::string> total;
  public:
    Inventory();
    void add(std::string token);
    void print();
	bool doesTokenExist(std::string token);
};

Inventory::Inventory()
{
	//constructor
}

void Inventory::add(std::string token)
{
	total.push_back(token);
}

void Inventory::print()
{
  for(std::vector<std::string>::iterator itr = total.begin() ; itr != total.end(); ++itr)
  {
      std::cout << ' ' << *itr;
  }
  std::cout << '\n';
}
bool Inventory::doesTokenExist(std::string token)
{
	bool exists = false;

	for(std::vector<std::string>::iterator i = total.begin() ; i != total.end(); ++i)
	{
		if(token == *i)
		{
			exists = true;
			break;
		}

	}

	return exists;
}

bool readFile(std::string name);

enum State
{
	FOR_EXP,
	HEAD1,
	HEAD2,
	HEAD3,
	BEGIN,
	FOR_EXP_END,
	EXP,
  //add more as becomes necessary
};

int findDepth(std::string fileName);


#endif /* Header_h */
