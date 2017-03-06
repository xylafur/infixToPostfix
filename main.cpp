#include <iostream>
#include <fstream>
#include "fixStacks.h"

int main(){
    std::string infix;
    ifstream fin;
    fin.open(argv[1]);
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

    return 0;
}
