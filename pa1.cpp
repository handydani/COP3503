//
//  main.cpp
//  Magic Square
//
//  Created by Daniela Isabel Travieso on 1/27/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <iostream>
using namespace std;
#include "pa1.h"

int main(int argc, const char * argv[])
{
        cout << "Enter the size of a magic square: ";
        //actual variable
        int inputSize = 0;
        //temp variable to check for decimals
        double tempInput = 0;
    
        //checks for input
        bool exit = false;
        while(!exit)
        {
            cin >> tempInput;
            //check for string and for decimal
            if(tempInput == 0 || tempInput != (int)tempInput)
            {
                cout << "stop tryin me sir. enter an integer next time.\n";
                //max showed me how to do this
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                inputSize = tempInput;
                //check for range
                if(inputSize >= 3 && inputSize <= 15 )
                {
                    //check for even numbers
                    if(inputSize % 2 != 0)
                    {
                        cout <<"thank you for cooperating.\n";
                        //exit while loop
                        exit = true;
                    }
                    else
                    {
                        cout << "stop tryin me sir. enter an odd number.\n";
                    }
                }
                else
                {
                    cout << "stop tryin me sir. enter a number between 3 and 15.\n";
                }
            }
    }
    
    //declare and initialize row/col to input values
    int row = inputSize;
    int col = inputSize;
    

    
//    cout << row << "\n"<< col << "\n" << endl;
   
    // 3, 5, 7, 9, 11, 13, 15
 
    
    
    //Magic Square 1
    
    cout << "Magic square 1 is: " << endl;
    int array1[row][col];
    
    //initialize the array to 0
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            array1[i][j] = 0;
        }
    }
    
    int p = 1; //p is progression from 1 to n*n
    row = inputSize - 1; //starting index
    col /= 2; //middle of square
    
    array1[row][col] = p;
    
    
    //iterates through all values of p
    for( p = 2 ; p <= (inputSize * inputSize) ; ++p )
    {
        
        
        if ( array1 [(row + 1) % inputSize] [(col+1) % inputSize] == 0 ) //check if there exists a value in the element
        {
            //ensures that the wrapping is taken care of
            //if it ever equals the inputSize (array index out of bounds) it will be modded by itself so it wraps around to 0
            row = ++row % inputSize;
            
            col = ++col % inputSize;
         
        }
        else //there's a value in the element
        {
//            cout << p <<endl;
            //col stays the same because it moves one up
            //mod ensures that it wraps
            //--row + inputSize decrements the row but ensures that it is never negative
            row = (--row + inputSize) % inputSize;
        }
        
         array1[row][col] = p;
        
    }
    
    
    //print with indentations
    for (int i = 0; i < inputSize; i++)
    {
        for (int j = 0; j < inputSize; j++)
        {
            
            if (array1[i][j] < 10)
            {
                 cout << " ";
                //if it has only one digit it needs 2 spaces
                //it would be less than 10 and less than 100
            }
            if (array1[i][j] < 100)
            {
                cout<< " ";
                //if it has 2 digits it only needs 1 space in between numbers
            }
            cout << array1[i][j] << " ";
            //space between numbers
        }
        cout << "\n";
        //next line
    }
    
    
    int sumRow = 0;
    int sumCol = 0;
    
    //rows
    cout << "Checking the sums of every row: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize;++j)
        {
            //ij, ji
            sumRow += array1[i][j];
        }
        cout << sumRow << " ";
        sumRow = 0;
    }
    
    //columns
    cout << "\nChecking the sums of every column: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //ij, ji
            sumCol += array1[j][i];
        }
        cout << sumCol << " ";
        sumCol = 0;
    }
    
    int sumDia1 = 0;
    int sumDia2 = 0;
    
    //i and j in the loop
    for(int j = inputSize-1, i = 0 ; i <inputSize; ++i, --j)
    {
        sumDia1 += array1[i][i];
        sumDia2 += array1[j][i];
    }
    
    cout << "\nChecking the sums of every diagonal: " << sumDia1 << " " << sumDia2 << endl;

    
    //Magic Square 2

    cout << "Magic square 2 is: " << endl;

    //declare array2
    int array2[inputSize][inputSize];
    
    //copy array1 to array2
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //reverse order
            array2[i][j] = array1[j][i];
        }
    }
    
    //print with indentations
    for (int i = 0; i < inputSize; i++)
    {
        for (int j = 0; j < inputSize; j++)
        {
            
            if (array2[i][j] < 10)
            {
                cout << " ";
                //if it has only one digit it needs 2 spaces
                //it would be less than 10 and less than 100
            }
            if (array2[i][j] < 100)
            {
                cout<< " ";
                //if it has 2 digits it only needs 1 space in between numbers
            }
            cout << array2[i][j] << " ";
            //space between numbers
        }
        cout << "\n";
        //next line
    }

    sumRow = 0;
    sumCol = 0;
    
    //rows
    cout << "Checking the sums of every row: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize;++j)
        {
            //ij, ji
            sumRow += array2[i][j];
        }
        cout << sumRow << " ";
        sumRow = 0;
    }
    
    //columns
    cout << "\nChecking the sums of every column: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //ij, ji
            sumCol += array2[j][i];
        }
        cout << sumCol << " ";
        sumCol = 0;
    }
    
    sumDia1 = 0;
    sumDia2 = 0;
    
    //i and j in the loop
    for(int j = inputSize-1, i = 0 ; i <inputSize; ++i, --j)
    {
        sumDia1 += array2[i][i];
        sumDia2 += array2[j][i];
    }
    
    cout << "\nChecking the sums of every diagonal: " << sumDia1 << " " << sumDia2 << endl;
    
    
    //Magic Square 3
    
    cout << "Magic square 3 is: " << endl;
    
    //declare array3
    int array3[inputSize][inputSize];
    
    
    for(int i = 0 ; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //initialize flipped array 3 to array 2
            array3[i][inputSize - j - 1] = array2[i][j];
        }
    }
    
    //print with indentations
    for (int i = 0; i < inputSize; i++)
    {
        for (int j = 0; j < inputSize; j++)
        {
            
            if (array3[i][j] < 10)
            {
                cout << " ";
                //if it has only one digit it needs 2 spaces
                //it would be less than 10 and less than 100
            }
            if (array3[i][j] < 100)
            {
                cout<< " ";
                //if it has 2 digits it only needs 1 space in between numbers
            }
            cout << array3[i][j] << " ";
            //space between numbers
        }
        cout << "\n";
        //next line
    }
    
    
    sumRow = 0;
    sumCol = 0;
    
    //rows
    cout << "Checking the sums of every row: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize;++j)
        {
            //ij, ji
            sumRow += array3[i][j];
        }
        cout << sumRow << " ";
        sumRow = 0;
    }
    
    //columns
    cout << "\nChecking the sums of every column: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //ij, ji
            sumCol += array3[j][i];
        }
        cout << sumCol << " ";
        sumCol = 0;
    }
    
    sumDia1 = 0;
    sumDia2 = 0;
    
    for(int j = inputSize-1, i = 0 ; i <inputSize; ++i, --j)
    {
        sumDia1 += array3[i][i];
        sumDia2 += array3[j][i];
    }
    
    cout << "\nChecking the sums of every diagonal: " << sumDia1 << " " << sumDia2 << endl;
    
 
    
    
    //Magic Square 4
    
    cout << "Magic square 4 is: " << endl;
    
    //declare array4
    int array4[inputSize][inputSize];
    
    //initialize flipped array4 with array1
    
    for(int i = 0 ; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //initialize flipped array 3 to array 2
            array4[inputSize - i - 1][j] = array1[i][j];
        }
    }
    
    //print with indentations
    for (int i = 0; i < inputSize; i++)
    {
        for (int j = 0; j < inputSize; j++)
        {
            
            if (array4[i][j] < 10)
            {
                cout << " ";
                //if it has only one digit it needs 2 spaces
                //it would be less than 10 and less than 100
            }
            if (array4[i][j] < 100)
            {
                cout<< " ";
                //if it has 2 digits it only needs 1 space in between numbers
            }
            cout << array4[i][j] << " ";
            //space between numbers
        }
        cout << "\n";
        //next line
    }
    
    
    sumRow = 0;
    sumCol = 0;
    
    //rows
    cout << "Checking the sums of every row: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize;++j)
        {
            //ij, ji
            sumRow += array4[i][j];
        }
        cout << sumRow << " ";
        sumRow = 0;
    }
    
    //columns
    cout << "\nChecking the sums of every column: ";
    for(int i = 0; i < inputSize; ++i)
    {
        for(int j = 0; j < inputSize; ++j)
        {
            //ij, ji
            sumCol += array4[j][i];
        }
        cout << sumCol << " ";
        sumCol = 0;
    }
    
    sumDia1 = 0;
    sumDia2 = 0;
    
    for(int j = inputSize-1, i = 0 ; i <inputSize; ++i, --j)
    {
        sumDia1 += array4[i][i];
        sumDia2 += array4[j][i];
    }
    
    cout << "\nChecking the sums of every diagonal: " << sumDia1 << " " << sumDia2 << endl;
    
    
    //YAY!!!
    
    
    return 0;
}

