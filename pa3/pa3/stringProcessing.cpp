#include <string>
#include <iostream>

int main()
{

  std::string s1 = "hello";
  std::string s2 = " world";

  std::cout << "comparing two strings gives us "<<s1.compare(s2) << std::endl;
  //output is 72

  /*
    0: equal
    +: not equal. 1st non matching character is greater in value based on ASCII table
    -: not equal. 1st non matching character in Var is less in value based on ASCII table than in compare string
  */


  std::cout << "the size of s1 is " << s1.size() <<std::endl;

  std::cout << "similar to an array, strings can be accessed like s1[2] = " << s1.at(2) << std::endl;

  s1 = "this is a string";
  s2 = "is";
  std::cout << "s1 is [ " << s1 << " ] and s2 is [" << s2 << "] " << std::endl;
  std::cout << "you can also search for an array by using s1.find(s2) given by: ";
  std::cout << s1.find(s2) << std::endl; // output: 2
  std::cout << "searching for 'is a' results in: ";
  std::cout << s1.find("is a") << std::endl; // output: 5

  //returns string::npos if no occurrences


  std::cout << "a substring of s1 is " << s1.substring(5,8) <<std::endl;
  //start at position 5 and end at length 8

  s1 = "this is a string";
  s2 = "this is another string";
  s1.swap(s2);
  std::cout << s1 << std::endl; // output: “this is another string”
  std::cout << s2 << std::endl; // output: “this is a string”


  return 0;
}
