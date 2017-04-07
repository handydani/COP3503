#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

using namespace std;

int main(int argc, char* argv[])
{
    
    
    List ll;
    
    for(int i = 0; i < 32; i++)
    {
        ll.addNode("Free");
    }
    
    ll.printList();
    for(int i = 0; i < 32; i++)
    {
        ll.addNode("PA2");
    }
    ll.printList();
    
    return 0;
}

