/*
 Daniela Isabel Travieso
 PA2 - Linked List
 COP3503
 Description: This is a program to mimic the memory management processes of an OS
 
 */
#include <iostream>
#include <string>
#include "pa2.h"
int main(int argc, char * argv[])
{
    //argc is argument count
    //argv is an array of c strings
    //command args
    std::string *cppArgs = new std::string[argc];
    std::string algorithm = "";
    for(int i = 0; i != argc; ++i)
    {
        cppArgs[i] = std::string(argv[i]);
        
    }
    
    if(argc != 2)
    {
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    if(cppArgs[1] == "best")
    {
        std::cout << "Using best fit algorithm" << std::endl;
        algorithm = "best";
    }
    else if(cppArgs[1] == "worst")
    {
        std::cout << "Using worst fit algorithm" << std::endl;
        algorithm = "worst";
    }
    else
    {
        //you suck
        std::cout << "Stop that!" << std::endl;
        return 1;
    }
    
    //best or worst
        //menu logic
            //linked lists
    
    int selection = 0;
    
    while(selection != 5)
    {
        //checks
        std::cout << "1. Add program \n";
        std::cout << "2. Kill program \n";
        std::cout << "3. Fragmentation \n";
        std::cout << "4. Print Memory \n";
        std::cout << "5. Exit \n";
        std::cout << "choice - ";
        double selectionTemp = 0;
        std::cin >> selectionTemp;
        
        if(isValidInput(selectionTemp, 5)) //checks if input is valid and if the value is within range
        {
            selection = selectionTemp;
        }
        
        LinkedList linkList = *new LinkedList();
        double programNumTemp = 0;
        int programNum = 0;
        
        switch(selection)
        {
            case 1:
            {
                //add method
                
                double size = 0;
//                int index = 0;
                
                std::cout << "Program name - P";
                std::cin >> programNumTemp;
                    if(isValidInput(programNumTemp, 1000))
                        programNum = programNumTemp;
                    else
                        return 1;
                std::cout << "Program size - ";
                std::cin >> size;
                
                if(isValidInput(size, 128))
                {
                    
                    linkList.add(programNum, size, algorithm);
                    
                }
                else if (size > 128)
                {
                    std::cout << "Error, not enough memory for program " << programNum << std::endl;
                }
                else
                {
                    continue;
                }
                break;
            }
            case 2:
            {
                //kill method
                
                std::cout << "Program name - P";
                std::cin >> programNumTemp;
                if(isValidInput(programNumTemp, 1000))
                    programNum = programNumTemp;
                else
                    return 1;
                linkList.remove(programNum);
                
                break;
            }
               
            case 3:
            {
                //fragment method
                std::cout << "There are " << linkList.getFragment() << " fragment(s)" << std::endl;
                
                break;
            }
               
            case 4:
            {
                //print
                linkList.print();
                
                break;
            }
                
            case 5:
            {
                //no need to write anything here
                
                
                
                break;
            }
                
            default:
            {
                std::cout << "Stop that!" << std::endl;
                break;
            }
        }

        
    }
    
    return 0;
    //end of main
};
bool isValidInput(double tempInput, int range)
{
    bool isValid = false;
    //actual variable
    int input = 0;
    
    //checks for input
        //check for string and for decimal
        if(tempInput == 0 || tempInput != (int)tempInput)
        {
            std::cout << "Enter an integer next time.\n";
            //if it's a string the buffer needs to be cleared
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else
        {
            input = tempInput;
            //check for range
            if(input <= range && input > 0)
            {
                isValid = true;
            }
            
        }
    return isValid;
}

//NODE

Node::Node(std::string prgName) //initializes the Node with the appropriate data
{
    setName(prgName);
}

void Node::setName(std::string prgName) //change name
{
    this->prgName = prgName;
}


std::string Node::getName()//get the name of a program
{
    return prgName;
}



//LINKED LIST

LinkedList::LinkedList() //constructor
{
    head = new Node("FREE"); // is this necessary??? maybe it needs to be null?
    Node *curr = head;
    for(int i = 0; i < 31; ++i)
    {
        curr->next = new Node("FREE");
        curr = curr->next;
    }
    curr->next = nullptr;
}

void LinkedList::add(int name, int prgSize, std::string arg)
{
    // MAJOR WIP

    
    Node *prev = head;
    Node *curr = head;
    Node *next = head->next;
   
    prev->next = curr;
    curr->next = next;
    
    int totalPages = prgSize/4; //1
    if(prgSize%4 != 0){
        ++totalPages;
    }
    
    std::string convertedName = "P" + std::to_string(name);
    
    int connectedNodes = 0;
    bool wasFree = false;
//    bool exit = false;
    int minimum = 32;
    bool full = false;
//    int count = 0; //startcount
//    int beginning = 0; //beginning
//    int best = 0; //bestindex
    
    if(arg == "best")
    {
        
//        while (next != nullptr)
//        {
//            if(curr->getName() == convertedName)
//            {
//                std::cout << "Error, program " << convertedName << " is already running."<< std::endl;
//                return;
//            }
//            if(curr->getName() == "FREE" )
//            {
//                while (curr->getName() == "FREE")
//                {
//                    if(next != nullptr){
//                        connectedNodes++;
//                        curr = curr->next;
//                        count++;
//                    }
//                    else
//                    {
//                        break;
//                    }
//                }
//                
//                if(connectedNodes >= totalPages){
//                    if (connectedNodes < minimum){
//                        minimum = connectedNodes;
//                        beginning = count - connectedNodes;
//                        best = beginning;
//                    }
//                }
//                
//            }
//            else if (next != nullptr)
//            {
//                curr = curr->next;
//                ++count;
//            }
//            connectedNodes = 0;
//            
//        }
//        
//        if(minimum >= totalPages)
//        {
//            Node *iterate = curr;
//            for (int i = 0; i < totalPages; ++i)
//            {
//                iterate->setName(convertedName);
//                iterate = iterate->next;
//            }
//        }
        
        
        
        
//        //best fit finds the smallest hole that is big enough
        for(int i = 0; i < 32 ; ++i)
        {

            
            if(curr->getName() == "FREE" )
            {
                if(!wasFree) //transition point at the beginning of a string of nodes
                {
                    connectedNodes = 0; //reset counter to 0
                    wasFree = true; //string of nodes has begun
                    
                }
                ++connectedNodes;
                if(minimum > connectedNodes)
                {
                    minimum = connectedNodes;
                }
                
            }
            else
            {
                
                //reached the end of a sequence of free nodes
                wasFree = false;
     
                
            }
            
            if(minimum >= totalPages)
            {

                //if this sequence of nodes is the smallest possible
                while(connectedNodes != 0)
                {
                    Node *addedNode = new Node(convertedName);
                    
                    prev->next = addedNode;
                    curr = addedNode;
                    curr->next = next;
                    
                    prev = curr;
                    if(next != nullptr)
                    {
                        curr = next;
                        next = next->next;
                    }
                    ++i;
                    --connectedNodes;
                    
                }
                
                std::cout << "Program " << convertedName << " added successfully: " << totalPages << " page(s) used." << std::endl;
                return;
            }
    }// end of for loop
        std::cout << "Error, Not enough memory for Program " << convertedName << std::endl;
        return;

    } //end of best fit algorithm
    
    else // if arg == worst
    {
        //worst fit finds the largest hole
        for(int i = 0; i < 32; ++i)
        {
            
            if(curr->getName() == convertedName)
            {
                std::cout << "Error, program " << convertedName << " is already running."<< std::endl;
                return;
            }
            if(curr->getName() == "FREE" )
            {
                
            }
            else
            {
                full = true;
            }
            
        }
        
        
    }
    
}
void LinkedList::print(void)
{
    //DONE - maybe
    
    
    //temp ptr that will be used for iterating
    Node *curr = head;
    Node *next = curr->next;
    for(int i = 0; i < 32; ++i) //loop through all pages of memory
    {
        std::cout << curr->getName() << " "; //prints out the name of the program
        if(i == 7 || i == 15 || i == 23 || i == 31) // formatting the rows
        {
            std::cout << "\n";
        }
        
        if(next != nullptr)
        {
            curr = next; //change the value of pointer so it iterates
            next = next->next;
        }
    }
    
} // end of print method

void LinkedList::remove(int name)
{
    //DONE - needs testing
    
    
    Node *iterator = head;
    int pageCounter = 0;
    std::string convertedName = "P" + std::to_string(name);
    
    //check if its "free", if it exists, if it reaches the end without finding it
    for(int i = 0; i < 32; ++i)
    {
        if(iterator->getName() == "FREE" || i == 31 )
        {
            std::cout << "Error, program " << convertedName << " doesn't exist in memory." << std::endl;
            return;
        }
        if(iterator->getName() == convertedName)
        {
            ++pageCounter;
            iterator->setName("FREE");
            
        }
        iterator = iterator->next;
    }
    std::cout << "Program " << convertedName << " successfully killed, " << pageCounter << " page(s) reclaimed." << std::endl;
    
}// remove method

int LinkedList::getFragment(void)
{
    //DONE - needs testing once kill and add are completed
    
    
    Node *curr = head; // node for current element
    Node *next = curr->next; // node for the next
    int frag = 0;

    for(int i = 0; i <32; ++i) //iterate through all pages
    {
        if(i == 31) // once at the end, point to null
        {
            next = nullptr;
        }

        if(curr->getName() == "FREE" && (next == NULL || next->getName() != "FREE")) //if reached end of fragment
        {
            //increment fragments
            ++frag;
        }
        
        curr = curr->next; // change the value of curr to the next element
        if (i != 31) //as long as it's not at the end, keep changing the value of next
        {
            next = next->next;
        }
        
    }
    
    return frag;
    
}//searches for fragments




