//
//  main.cpp
//  Lab5
//
//  Created by Daniela Isabel Travieso on 2/16/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a, int *b);
void print(int a, int b);
void swapThatsCooler( int &a, int &b);


int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello, World!\n";
    
    int a = 3;
    int b = 4;
    
    int* aPtr = &a;
//    int some =
    //print value of pointer
    cout << "value of a pointer: " <<  aPtr << endl;

    //print a
    cout << "value of a: " << *aPtr<< endl;
    
    
    //delete dynamic arrays
    //dynamic arrays with constant size !!!! dont do dat
    
    
    print(a, b);
    swapThatsCooler(a, b);
    print(a, b);
    
    return 0;
    
    
}
void swapThatWorks(int *a, int *b)
{
    int temp = *a;
    *b = temp;
    *a = *b;
}
void swapThatsCooler( int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swapThatDoesntWork( int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void print(int a, int b){
    cout << "The value of a is: " << a << endl;
    cout << "The value of b is: " << b << endl;

}
