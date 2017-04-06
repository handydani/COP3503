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

int main()
{

  std::string fileName = "";
  std::cout << "Please enter the name of the input file: " << std::endl;
  std::cin >> fileName;
  std::ifstream file(fileName);

  /**********************************/

  if(!file)
  {
    std::cout << "Something went wrong..." << std::endl;
    return 1;
  }

  std::cout << "Success! Proceeding... " << std::endl;

  /**********************************/

  // std::stack <char> s;
  // char token();
  // char bitch();
  // while( file.good() )
  // {
	// 	file >> token;
	// 	s.push(token);
	// }
  //
  // for(int i = 0; i < s.size(); ++i)
  // {
  //   bitch = s.top();
  //   std::cout << bitch << std::endl;
  //   s.pop();
  // }

  //find depth

  //keywords:
  //identifiers:
  //constant:
  //operators:
  //delimiter:

  //syntax errors:
  //close file
  /**********************************/


  file.close();
  return 0;
}
// StackClass readFile(){
//
//}
