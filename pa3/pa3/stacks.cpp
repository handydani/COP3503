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

  /*

  AVAILABLE COMMANDS:

    s.empty();
    s.size();
    s.top(); //get the element without removing it
    s.pop(); //remove the element
    s.push(someElement); //add the element
  */


	// for (int i=0; i!=str.size(); ++i) {
	// 	if(str[i]=='('){
	// 		s.push(str[i]);
	// 	}
	// 	if(str[i]==')'){
	// 		if(s.size()==0){
	// 			std::cout <<"Mismatch"<<std::endl;
	// 			return 1;
	// 		}
	// 		char checkParenthesis=s.top();
	// 		if(checkParenthesis=='('){
	// 			s.pop();
	// 		} else if(checkParenthesis==')'){
	// 			std::cout<<"Mismatch"<<std::endl;
	// 			return 1;
	// 		}
	// 	}
	// }
	// if(s.size()!=0){
	// 	std::cout<<"Mismatch"<<std::endl;
	// 	return 1;
	// }
	// std::cout<<"Good job my KITTEN_EMOJI 🐨"<<std::endl;

}
