//
//  main.cpp
//  Lab 4
//
//  Created by Daniela Isabel Travieso on 2/9/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello, World!\n";
    //pointers
    
    
    int a = 2;
    
    int *Pointer = &a;
    //star denotes a pointer
    // * = d reference operator
    // & the address of
    cout << "The value of a is " << a << endl;
    cout << "The value that Pointer points to is " << Pointer << endl; // prints 0x3208urfhu
    cout << "The value that Pointer points to is " << *Pointer << endl; //the star denotes, 'go to the address and give me its value'
    //

    
    
    return 0;
}
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    //printBitches(a, b);
    
}
void butt(){
    int a = 2;
    int b = 4;
    
    swap(a,b);
    //why won't it work??? a will be 2 and be will be 4
    //pass by value, values of a and b are copied
    //this can be resolved by using pointers

 //   swapWithPtrs(&a, &b);

}
void swapWithPtrs(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printBitches(int a, int b)
{
    cout << "the value of a is" << a;
    cout << "the value of b is" << b;

}



void moreLab()
{
    
    
//    Pizza *p3 = new Pizza();
//    (*p3).eatSlice();
//    p3->eatSlice();
//     delete p3;
//     p3 = nullptr
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
