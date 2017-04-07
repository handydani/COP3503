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

class StackClass
{

  private:

  public:
    StackClass();
};

class Inventory
{
  public:
    std::vector<std::string> total; //may or may not be useful
    std::vector<std::string> keywords;
    std::vector<std::string> identifiers;
    std::vector<std::string> constants;
    std::vector<std::string> operators;
    std::vector<std::string> delimiters;
    Inventory();


    bool doesTokenExist(std::string token);
    void incrementKeywords(std::string input);
    void incrementIdentifiers(std::string input);
    void incrementConstants(std::string input);
    void incrementOperators(std::string input);
    void incrementDelimiters(std::string input);
    void incrementTotal(std::string input); //may or may not be useful

    std::vector<std::string> getKeywords();
    std::vector<std::string> getIdentifiers();
    std::vector<std::string> getConstants();
    std::vector<std::string> getOperators();
    std::vector<std::string> getDelimiters();
    std::vector<std::string> getTotal(); //may or may not be useful
};

bool readFile(std::string name);

StackClass::StackClass()
{

}

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

  //find depth

  //keywords:
  //identifiers:
  //constant:
  //operators:
  //delimiter:

  //syntax errors:
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
