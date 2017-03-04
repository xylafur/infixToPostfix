#include "stack.h"
#include <iostream>


int main(){
    Stack<int> * myStack = new Stack<int>();
    myStack->push(5);
    myStack->push(6);
    myStack->push(7);

    std::cout << myStack->pop() << std::endl;

    myStack->print();

    delete(myStack);
    
    return 0;
}
