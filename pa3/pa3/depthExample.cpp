#include <iostream>
#include "pa3.h"
#include <fstream>
#include <string>
#include <stack>
#include <vector>


class DepthStack
{
	std::vector<int> vect;
public:
  DepthStack();

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
DepthStack::DepthStack()
{

}
enum State
{
	FOR_OR_EXP,
	FOR_1,
	FOR_2,
	FOR_3,
	FOR_BEGIN,
	EXP_OP,
	EXP_IDEN
	// ...more as an exercise for the reader
};

int main()
{

		std::string filename; //string variable to hold text file name
		std::cout << "enter a file name\n";
    std::cin >> filename; //get file name from user

    std::ifstream codefile; //make file object called CodeFile

    codefile.open(filename,std::ios::in); //file is opened and set for input operations

    std::string codeline;

		DepthStack* stack = new DepthStack();

		int maxDepth = -1;
		int currDepth = 0;

    if (codefile.is_open() == true)
    {
        while (getline(codefile, codeline))
        {
						codefile >> codeline;
            std::cout << codeline << "\n";

						if(codeline == "BEGIN")
						{
							//add to keyword list if not already existing
							stack->push(1);
							currDepth++;
							if(currDepth > maxDepth)
							{
								maxDepth = currDepth;
							}
						}
						if(codeline == "END")
						{
							//add to keyword list if not already existing
							stack->pop();
							currDepth--;
						}
        }

				std::cout << "the size of the stack is "<< stack->size() << " and the size should be 0" << std::endl;

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


				std::cout <<"curr depth is " << currDepth << " and max depth is " << maxDepth << std::endl;


        codefile.close();
				return 0;
    }
		else
		{
			return 1;
		}





	std::ifstream file("code.txt");
	std::string nextWord;

	State state = FOR_OR_EXP;

	for(;;)
	{

		file >> nextWord;

		if (!file.good())
		{
			break;
		}

		switch(state)
		{
			case FOR_OR_EXP:
					if (nextWord == "FOR")
					{
						std::cout << "checkpoint 1\n";
						state = FOR_1;
					}
					// else if (isLowercaseOrEqualSign(nextWord))
					// {

							// this func is too simplistic. need to check for word on left,
							// word on right, and the presense of an equal sign.
					// 	state = EXP_OP;
					// }
					else
					{
						// error condition
					}
			break;
			case FOR_1:
					if (nextWord.length() < 3)
					{
						std::cout << "checkpoint 2\n";
						std::cout << "you're very wrong";
					}
					if (nextWord[0] != '(' || nextWord[nextWord.length()-1] != ',')
					//|| nextWord[nextWord.length()-1] != ')'
					{
						std::cout << "checkpoint 2\n";
						std::cout << "you're missing a () or a ,";
					}
					//continue to make if elses to parse through (i, 10, ++)
					std::cout << "checkpoint 2\n";
					state = FOR_BEGIN;
			break;
			case FOR_BEGIN:
					if(nextWord == "BEGIN")
					{
						//u did a good
						std::cout << "checkpoint 3.1\n";

					}
					else if(nextWord == "FOR")
					{
						std::cout << "checkpoint 3.2\n";

						// ya dun goofed
						// wwoops
					}
					else if(nextWord[1] == '=')
					{
						std::cout << "checkpoint 3.3\n";

					}
					else
					{

						//yo
					}
					//check out tokenization

			break;
			case FOR_2:
			break;
			case FOR_3:
			break;
			case EXP_OP:
			break;
			case EXP_IDEN:
			break;

		} //end of switch




	} //end of for loop
  return 0;
} //end of main
