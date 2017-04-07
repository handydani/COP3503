//
//  main.cpp
//  cmdarg
//
//  Created by Daniela Isabel Travieso on 3/2/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, char * argv[]) {
    
    //argc is argument count
    //argv is an array of c strings
    
    std::string *cppArgs = new std::string[argc];
    for(int i = 0; i != argc; ++i){
        cppArgs[i] = std::string(argv[i]);
        
    }
    for (int i = 0; i!= argc; ++i)
    {
        std::cout <<"argv[" <<i<<"] = "<< cppArgs[i]<< std::endl;
    }
    
    if (argc >= 2)
    {
        //blah too much stuff
        return 1;
        
    }
    if(cppArgs[1] == "best")
    {
        
    }
    else if(cppArgs[1] == "worst")
    {
   
    }
    else
    {
        
        //you suck
    }
    // insert code here...
    return 0;
}
