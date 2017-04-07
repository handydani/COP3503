//
//  Person.cpp
//  Lab6
//
//  Created by Daniela Isabel Travieso on 2/23/17.
//  Copyright © 2017 Daniela Isabel Travieso. All rights reserved.
//

#include "Person.hpp"
#include <iostream>

class Person{
    int age;
    std::string name;
public:
    Person(int age, std::string name) : age(age), name(name) {}
    std::string getName(){
    return name;
    }
    int getAge(){
        return age;
    }
    void haveABirthday(){
        if (age <120)
        {
            age++;
        }
    }
};

int main ()
{
    Person p (22, "Max");
    const Person trev(21, "Trev");
    
//    std::cout << "The age of person p is " << trev.getAge() << std::endl;

    
    return 0;
}
