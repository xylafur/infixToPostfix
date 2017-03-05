#include <iostream>
#include "fixStacks.h"

int main(){
    std::string infix = "A * ( B + C )";
    Converter * con = new Converter(infix);
    //con->printStacks();
    con->print();
    delete(con);

    infix = "A+B";
    con = new Converter(infix);
    con->print();
    delete(con);


    infix = "(A*B)+(C/D)";
    con = new Converter(infix);
    con->print();
    delete(con);

    return 0;
}
