#include <iostream>
#include "fixStacks.h"

int main(){
    std::string infix = "A * ( B + C )";
    Converter * con = new Converter(infix);
    con->printStacks();
    delete(con);
    return 0;
}
