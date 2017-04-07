//
//  lab2.cpp
//  yo
//
//  Created by Daniela Isabel Travieso on 1/26/17.
//
//

#include "lab2.hpp"
#include <iostream>


int main()
{
    
    std::string s = "Hello World";
    std::cout << s << std::endl << "Enter a number: ";
    std::string i;
    std::cin >> i;
    std::cout << "You said: " << i << std::endl;
    bool isPalindrome = true;
    
    // %
    // /=
    for(int j = 0; j < i.length()/2; ++j )
    {
        if( i[j] != i[i.length()-j-1])
        {
            isPalindrome = false;
            break;
        }
       
    }
    
    std::cout << "Is it a palindrome? " << isPalindrome << std::endl;
    
    return 0;
}

