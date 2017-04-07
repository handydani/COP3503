//
//  classes.cpp
//  Lab 4
//
//  Created by Daniela Isabel Travieso on 2/9/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include <stdio.h>
#include <iostream>

class Pizza
{
    private:
        int numToppings;
        int slicesLeft = 8;
    
    public:
        Pizza()
        {
            numToppings = 1;
        }
        Pizza(int numToppings)
        {
            this->numToppings = numToppings;
        }
        bool eatSlice()
        {
            if(slicesLeft > 0)
            {
                --slicesLeft;
                return true;
            }
            return false;
        }
};

int main()
{
    Pizza p;
    Pizza p2(4);
    bool pizzGone = false;
    while(!pizzGone){
        pizzGone = p.eatSlice();
    }
}
