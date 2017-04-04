//stacks example
#include <iostream>
#include "stacksHeader.h"
#include <fstream>
#include <string>
#include <stack>


int main() {
	const int myArray[7] = {1,2,3,4,5,6,7};

	std::stack <int> s;
  std::cout  << "Houston there is a stack!" <<std::endl;

  std::cout << "size is " << s.size() << '\n';

  if(s.empty() == true) {
    std::cout << "The stack is empty" << std::endl;
  }
  else{
    std::cout << "The stack is full" << std::endl;
  }

  std::cout << "Time to add stuff to it!" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		s.push(i);
	}
	std::cout << "size is " << s.size() << '\n';

	int bitch = 0;

	for(int i = 0; i < 10; ++i)
	{
		bitch = s.top();
		std::cout << bitch << std::endl;
		s.pop();
	}

  /*
  AVAILABLE COMMANDS:

    s.empty();
    s.size();
    s.top(); //get the element without removing it
    s.pop(); //remove the element
    s.push(someElement); //add the element
  */



}
