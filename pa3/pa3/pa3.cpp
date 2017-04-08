//
//  main.cpp
//  pa3
//
//  Created by Travieso,Daniela I on 3/31/17.
//  Copyright © 2017 Travieso,Daniela I. All rights reserved.
//

#include <iostream>
#include "pa3.h"
#include <fstream>
#include <string>
#include <stack>
#include <vector>


class DepthStack
{
	std::vector<std::string> vect;
public:
  DepthStack();

	void push(std::string data)
	{
		vect.push_back(data);
	}
	void pop()
	{
		vect.pop_back();
	}
	std::string top()
	{
		std::string data = vect.back();
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
    bool add(std::string token);
    void print();
};

Inventory::Inventory()
{

};

bool Inventory::add(std::string token)
{
  total.push_back(token);
}

void Inventory::print()
{
  for(std::vector<std::string>::iterator itr = total.begin() ; itr != total.end(); ++itr)
  {
      std::cout << ' ' << *itr << "\n";
  }
  std::cout << '\n';
}

bool readFile(std::string name);

enum State
{
	FOR_OR_EXP,
	FOR_1D,
	FOR_2D,
	FOR_3D,
	FOR_BEGIN,
	EXP_OP,
	EXP_IDEN
  //add more as becomes necessary
};


int main()
{

  std::string fileName = "";
  std::cout << "Please enter the name of the input file: " << std::endl;
  std::cin >> fileName;

  if(!readFile(fileName))
  {
    return 1;
  }

  std::ifstream file(fileName);

  /**********************************/

  std::string token = "";

  Inventory* myInventory = new Inventory();

  while(getline(file, token))
  {
    myInventory->add(token);
  }

  myInventory->print();



  /**********************************/


  
/*
  _____ ___  ____   ___    _     ___ ____ _____
 |_   _/ _ \|  _ \ / _ \  | |   |_ _/ ___|_   _|
   | || | | | | | | | | | | |    | |\___ \ | |
   | || |_| | |_| | |_| | | |___ | | ___) || |
   |_| \___/|____/ \___/  |_____|___|____/ |_|


   PARSE TOKENS

   RESEARCH STATE MACHINE

   RESEARCH RELEVANT STRING METHODS

   FIND DEPTH

*/


  //find depth

  //keywords:
  //identifiers:
  //constant:
  //operators:
  //delimiter:

  //syntax errors:

/*
  _                     _                           _                 _
(_)_ __  ___  ___ _ __| |_    __ _  ___   ___   __| |   ___ ___   __| | ___
| | '_ \/ __|/ _ \ '__| __|  / _` |/ _ \ / _ \ / _` |  / __/ _ \ / _` |/ _ \
| | | | \__ \  __/ |  | |_  | (_| | (_) | (_) | (_| | | (_| (_) | (_| |  __/
|_|_| |_|___/\___|_|   \__|  \__, |\___/ \___/ \__,_|  \___\___/ \__,_|\___|
                             |___/
_
| |__   ___ _ __ ___
| '_ \ / _ \ '__/ _ \
| | | |  __/ | |  __/
|_| |_|\___|_|  \___|

*/

  /**********************************/


  file.close();
  return 0;
}

bool readFile(std::string name)
{
  bool doesFileExist = false;
  std::ifstream file(name);

  if(file)
  {
    std::cout << "Success! Proceeding... " << std::endl;
    doesFileExist = true;
  }
  else
  {
    std::cout << "Something went wrong..." << std::endl;
  }
  file.close();
  return doesFileExist;

}
