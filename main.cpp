#include <iostream>
#include <fstream>
//#include "converter.h"
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

    //fin >> infix;

    while (!fin.eof() )
    {
        fin >> infix;
        Converter * con = new Converter(infix);
        //con->printStacks();
        con->print();
        delete(con);

        fin >> infix;
    }


}

void doIt(std::string s){
        Converter *con = new Converter(s);
        con->print();
        delete(con);

}

void getUserInput(){
    bool cont = true;

    std::string s;
    //while(cont){
      
    {
        std::cout << "Enter an infix string to convert." << std::endl;
        getline(std::cin, s);
        //theres an error right around here
        doIt(s);        
        
       // std::cout << "Would you like to enter another infix input? (0:no, 1:yes)" << std::endl;
        //getline(std::cin, s);
        //if(s[0] - '0' == 0)
            //cont = false;

    }
    
}

int main(int argc, char ** argv){
    //useFileInput(argv[1]);
    getUserInput();
    
    return 0;
}
