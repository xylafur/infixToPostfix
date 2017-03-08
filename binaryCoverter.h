#ifndef BINARY_CONVERT
    #define BINARY_CONVERT
#include <iostream>
void printAsNumber(int number, int base){
    int remainder = base % number;
    printAsNumber(number/base, base);
    std::cout << remainder;
}

#endif
