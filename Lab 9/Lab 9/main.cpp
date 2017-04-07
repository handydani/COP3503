//
//  main.cpp
//  Lab 9
//
//  Created by Daniela Isabel Travieso on 3/23/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>
#include <fstream>

const std::string FILENAME_INPUT = "input.txt";
int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::ifstream file(FILENAME_INPUT);
    int bestnum = 0;
    std::string name = "";
    double bestdouble = 0;
    std::string name2 = "";
    
    file >> bestnum;
    std::cout << "best num is " << bestnum <<std::endl;
    file.close();
//    ofstream output_filename;
    //ofstream
    //ifstream
    
    return 0;
}
