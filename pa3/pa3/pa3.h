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
  int depth = 0;
  public:
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




#endif /* Header_h */
