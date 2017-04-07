//
//  Exercise.cpp
//  Lab3
//
//  Created by Daniela Isabel Travieso on 2/2/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include "Exercise.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "Hey enter your id:" << endl;
    int id = 0;
    cin >> id;
    
    int array[8];
    int a;
    int temp;
    for(int i = 0; i != 8; ++i)
    {
        a = 10000000;
        temp = id%a;
        array[i] = id/a;
        a /= 10;
        id = temp;
       
    }
    
    for(int i = 0; i != 8;++i)
    {
        cout << array[i];
    }
    return 0;
    
}


