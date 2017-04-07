//
//  main.cpp
//  Lab6
//
//  Created by Daniela Isabel Travieso on 2/23/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a = 2;
    a = 4;
    a++;
    
    std::cout << "value of a is " << a << std::endl;
    
    
    const int b = 4;
    std::cout << "value of b is " << b << std::endl;
    //b++; c++ yells at you
    
    
    int aa = 3;
    int bb = 5;
    int *aaPtr = &aa;
    //modify the value it points to
    *aaPtr = bb;
    std::cout << "value of aaPtr is " << *aaPtr << std::endl;

    (*aaPtr)++;
    std::cout << "value of aaPtr is " << *aaPtr << std::endl;

    
    //modify the pointer itself
    std::cout << "address of aaPtr is " << aaPtr << std::endl;

    aaPtr = &bb;

    std::cout << "address of aaPtr is " << aaPtr << std::endl;
    
    
    //const and pointers
    
//    a const ptr to an int ****
    int * const aConstPtr = &a;
//    aConstPtr = &b //illegal
    *aConstPtr = 12;
    
    
//    a point to a const int
    int const * aPtrtoConst = &a;
    const int * aPtrtoConst2 = &a;
    
    aPtrtoConst = &b;
//    *aPtrtoConst = 12 //illegal
    
//    how do we make a const pointer to a const int
    //can modify neither the pointer nor the value it points to
    int const * const aConstPtrtoAConstInt = &a;
    
    
//
    
    
    
    
    
    
    
    return 0;
}
