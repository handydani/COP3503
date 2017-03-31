//file io example
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, const char * argv[])
{
    // insert code here...


    //file to take input from
    std::ifstream file("input.txt");

    //check if the file exists/opened correctly
    if(!file){
        std::cout << "error" <<std::endl;
        return 1;
    }


    std::string line;

//    get the next line while it exists
//    while(getline(file, line))
//    {
//        std::cout << line << std::endl;
//    }

    std::string name;

    //cin
    file >> line >> name;

    std::cout << line << "\t" << name <<std::endl;

    //file to make output of
    std::ofstream ofile("newFile2.txt");

    //cout
    ofile << line << " butt " << name << std::endl;


    //always close files
    ofile.close();
    file.close();




    return 0;
}
