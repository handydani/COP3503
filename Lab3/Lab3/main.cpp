//
//  main.cpp
//  Lab3
//
//  Created by Daniela Isabel Travieso on 2/2/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxSize = 15;
int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello, World!\n" << endl;
    
    string myString = "Hello";
    int num = 2;
    num = num * 3;
    myString += to_string(num);
    cout << myString << endl;
    
    
    string numStr = "1337";
    num = stoi(numStr);
    cout << num << endl;
    
    //static 1d arrays
    cout <<"Enter a number" << endl;
    int input = 0;
    cin>> input;
    //int arr[input]; //illegal
    //always make constant variables for arr[input]
    int arr[maxSize] = {0,1,2,3};
    
    
    //static 2d arrays
    
    int ms[maxSize][maxSize] = {};
    
    
    //dynamic 1d arrays
    
    int *dArr = new int[input]; //valid
    
    for(int i = 0; i!= input ; ++i){
        dArr[i] = 0;
    }
    dArr[0] =2;
    
    string str = "124";
    
    delete [] dArr;
    
    
    //dynamic 2d arrays
    
    int **d2DArr = new **int[input];
    for(int i = 0; i != input ; ++i){
        d2DArr[i] = new int[input];
        for(int j = 0; j != input; ++j){
            d2DArr[i][j] = 0;
        }
    }
    
    //whew
    
    d2DArr[0][1] = 4;
    
    //delete it!
    
    for(int i = 0;  i!= input; ++i){
        delete [] d2DArr[i];
        
    }
    delete [] d2DArr;
    
    
    
    
    
    return 0;
}
