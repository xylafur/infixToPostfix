#include <iostream>
#include <fstream>
#include "fixStacks.h"

void useFileInput(char * str){
    std::string infix;
    ifstream fin;
    fin.open(str);
    if (fin.fail())
    {
        cout << "File did not open" << endl;
        exit (1);
    }

    fin >> infix;

    while (!fin.eof() )
    {
        Converter * con = new Converter(infix);
        //con->printStacks();
        con->print();
        delete(con);

        fin >> infix;
    }


}
void getUserInput(){
    bool cont = true;

    while(cont){
        std::cout << "Enter an infix string to convert." << std::endl;
        std::string s;
        getline(std::cin, s);
        Converter * con = new Converter(s);
        con->print();
        delete(con);

        std::cout << "Would you like to enter another infix input? (0:no, 1:yes)" << std::endl;
        getline(std::cin, s);
        if(s[0] - '0' == 0)
            cont = false;
    }
    
}

int main(int argc, char ** argv){
    //useFileInput(argv[1]);
    getUserInput();
    
    return 0;
}
