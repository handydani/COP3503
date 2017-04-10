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

	/****************EXAMPLE OF ADDING INVENTORY AND PRINTING******************/

	// std::string token = "";
	//
	// Inventory* totalInventory = new Inventory();
	//
	// while(getline(file, token))
	// {
	// 	totalInventory->add(token);
	// }
	//

	// totalInventory->print();

	/****************INVENTORY******************/

	Inventory * keywords = new Inventory();
	Inventory * identifiers = new Inventory();
	Inventory * constants = new Inventory();
	Inventory * operators = new Inventory();
	Inventory * delimiters = new Inventory();
	Inventory * syntax = new Inventory();

	/****************STATE MACHINE******************/

	std::string nextWord;

	State state = FOR_EXP;

	Stack * fakeStack = new Stack();
	fakeStack->push();
	fakeStack->pop();

	int size = 0;
	for(;;)
	{

		file >> nextWord;

		if (!file.good())
		{
			break;
		}

		int iteration = 0;


		switch(state)
		{
			size = nextWord.size();
			case FOR_EXP:  //expecting either a FOR or EXPression

				char temp(nextWord.at(size/2));
				++iteration; //iteration to debug

				if (nextWord == "FOR")
				{
					if(!(keywords->doesTokenExist(nextWord))) //if it doesn't exist, add to keywords
					{
						keywords->add(nextWord);
					}
					state = HEAD1; //change state to the first part of the header
				}
				else if(temp == '=') //if it's an expression, half of that is going to be =
				{
					if(!(operators->doesTokenExist("=")))
					{
						operators->add("=");
					}
					if(!(identifiers->doesTokenExist(nextWord.substr(0, size/2)))) //add if exists
					{
						//sum=sum
						identifiers->add(nextWord.substr(0, size/2));
					}

					state = EXP; //change state to expect expression tokens
				}
				else
				{
					std::cout << "an error occurred at iteration "<< iteration << std::endl;
					return 1;
					// error condition
				}

			break;
			case HEAD1: //first part of header, (j,
				++iteration;
				state = HEAD2;

				if (size == 3)
				{
					if(!(identifiers->doesTokenExist(nextWord.at(1))))
					{
						identifiers->add(nextWord.at(1)); //add the identifier
					}
					if(!(delimiters->doesTokenExist(nextWord.at(2))))
					{
						delimiters->add(nextWord.at(2)); //add the comma
					}
				}
				if(size < 3)
				{
					//there exists a syntax errror
					std::cout << "an error occurred in syntax"<< std::endl;

				}
				else if(size > 3)
				{
					//there exists a syntax errror
					std::cout << "an error occurred in syntax"<< std::endl;
				}
				else
				{
					std::cout << "an error occurred at iteration "<< iteration << std::endl;
					return 1;
				}

			break;
			case HEAD2: //second part of header, 10, or 5,

				++iteration;

				state = HEAD3;

				if(!(delimiters->doesTokenExist(nextWord.at(size - 1))))
				{
					delimiters->add(nextWord.at(size - 1)); //add the comma
				}


				if(!(constants->doesTokenExist(nextWord.substr(0, size - 1 ))))
				{
					constants->add(nextWord.substr(0, size - 1 )); //add the number
				}

			break;
			case HEAD3: //third part of header, ++)
				++iteration;
				state = BEGIN;

				if (size == 3)
				{
					if(!(identifiers->doesTokenExist(nextWord.substr(0, 1))))
					{
						identifiers->add(nextWord.substr(0,1)); //add the ++ part
					}
				}
				else if(size > 3)
				{
					//there exists a syntax errror
					if(!(syntax->doesTokenExist(")")))
					{
						syntax->add(")");
					}
					std::cout << "an error occurred in syntax"<< std::endl;
				}
				else
				{
					std::cout << "an error occurred at iteration "<< iteration << std::endl;
					return 1;
				}

			break;
			case BEGIN: //FOR_EXP_END
				++iteration;
				state = FOR_EXP_END;
				if(nextWord == "BEGIN")
				{
					state = FOR_EXP_END;
				}
				else if(nextWord != "BEGIN")
				{
					if(!(syntax->doesTokenExist(nextWord)))
					{
						syntax->add(nextWord);
					}
					std::cout << "an error occurred in syntax"<< std::endl;
				}
				else
				{
					std::cout << "an error occurred at iteration "<< iteration << std::endl;
					return 1;
				}

			break;
			case FOR_EXP_END: // END or FOR_EXP
				++iteration;

				if(nextWord == "FOR")
				{
					state = HEAD1;

					if(!(keywords->doesTokenExist(nextWord)))
					{
						keywords->add(nextWord);
					}

					//done
				}
				else if(nextWord == "END")
				{
					state = FOR_EXP_END;

					if(!(keywords->doesTokenExist(nextWord)))
					{
						keywords->add(nextWord);
					}

					//done
				}
				else if(nextWord.at(size()/2) == "=")
				{

					state = EXP;
					if(!(operators->doesTokenExist("=")))
					{
						operators->add("=");
					}
					if(!(identifiers->doesTokenExist(nextWord.substr(0,size/2)))) //add if exists
					{
						//sum=sum
						identifiers->add(nextWord.substr(0,size/2));
					}

				}
				else
				{
					std::cout << "an error occurred at iteration "<< iteration << std::endl;
					return 1;
				}


			break;
			case EXP: //FOR_EXP_END
				++iteration;

				if(nextWord == "+" || nextWord == "-" || nextWord == "*" || nextWord == "/")
				{
					if(!(operators->doesTokenExist(nextWord)))
					{
						operators->add(nextWord);
					}
				}
				else //it's a j; or i
				{
					if(nextWord.at(size - 1) == ";")
					{
						if(!(delimiters->doesTokenExist(";")))
						{
							delimiters->add(";");
						}

						if(!(identifiers->doesTokenExist(nextWord.at(0))))
						{
							identifiers->add(nextWord.at(0));
						}

						state = FOR_EXP;
					}
					else if(!(identifiers->doesTokenExist(nextWord))) //if it's an i j k sum etc.
					{
						identifiers->add(nextWord);
					}
					else
					{
						std::cout << "an error occurred at iteration "<< iteration << std::endl;
						return 1;
					}

				}


			break;
			case default:
				std::cout << "rip"<<std::endl;
			break;
		} //end of switch


	} //end of for loop

	/****************OUTPUT******************/

	std::cout << "The depth of nested loop(s) is " << findDepth(fileName) << std::endl;

	std::cout << "Keywords: " << keywords->print() << std::endl;
	std::cout << "Identifiers: " << identifiers->print()<< std::endl;
	std::cout << "Constants: " << constants->print() << std::endl;
	std::cout << "Operators: " << operators->print() << std::endl;
	std::cout << "Delimiters: " << delimiters->print() << std::endl;
	std::cout << "Syntax Error(s): " << syntax->print() << std::endl;


  /**********************************/


  file.close();
  return 0;
} //end of main

bool readFile(std::string name)
{
  bool doesFileExist = false;
  std::ifstream file(name);

  if(file)
  {
    doesFileExist = true;
  }
  file.close();
  return doesFileExist;
}

int findDepth(std::string fileName)
{
		if(!readFile(fileName))
		{
			std::cout << "An error occurred." <<std::endl;
			return 0;
		}

		std::ifstream depthFile; //make file object called CodeFile

		depthFile.open(fileName,std::ios::in); //file is opened and set for input operations

		std::string codeLine;

		DepthStack* stack = new DepthStack();

		int maxDepth = -1;
		int currDepth = 0;


		while (getline(depthFile, codeLine))
		{
				depthFile >> codeLine;

				if(codeLine == "BEGIN")
				{
					//add to keyword list if not already existing
					stack->push(1);
					currDepth++;
					if(currDepth > maxDepth)
					{
						maxDepth = currDepth;
					}
				}
				if(codeLine == "END")
				{
					//add to keyword list if not already existing
					stack->pop();
					currDepth--;
				}
		}

		if( stack->size() != 0)
		{
			maxDepth--;
			if (stack->size() > 0)
			{
				//if there is a missing END then the size is positive
				//increment syntax error with END

			}
			if(stack->size() < 0)
			{
				//if there is a missing FOR then the size is negative
				//increment syntax error with FOR
			}
		}

		depthFile.close();

		return maxDepth;
}
