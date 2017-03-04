#ifndef INFIX_TO_POSTFIX
    #define INFIX_TO_POSTFIX
#include "stack.h"
#include <string>

//enum that we can use to easily determine the type of each next character
enum Type {operand, operat, space};

class Converter{
/*
 *  So my plan of action is that we will use three stacks to convert from infix
 *          notation to postfix notation.  We have one stack that holds all of
 *          the operands (such as A, B, C.. etc) and another for all of the
 *          operators.  The final stack, eval, will hold the final order of
 *          everthing.
 *
 *  Once the input (infix notation) has been eptied out into the eval stack 
 *          we can then easily convery it into its final form as a postfix
 *          string by popping off the values.
 *                  
 */
private:
    Stack<char> *eval, *operands, *operators;
    std::string infix, postfix;
    unsigned int index = 0; //curent position in infix
    int parenthesisLevel = 0; //how deep we are in parenthesis

    //using the enum from earlier to define the current character
    Type defineCharacter(){
        char currentChar = this->infix.at(index);
        switch(currentChar){
            case '(':
                parenthesisLevel++;
                return operat;
            case ')':
                parenthesisLevel--;
            case '/':
            case '*':
            case'+':
            case '-':
                return operat;
            case ' ':
                return space;
            default:
                return operand;
        }
    }
    //grabs the next character from the string and processes it
    void processCurrentChar(){
        Type charType = defineCharacter();
        if(charType == operand)
            this->operands->push(infix.at(index));
        else if(charType == operat)
            this->operators->push(infix.at(index));
    }
    void convert(){
        while(index < infix.length()){
            processCurrentChar();
            this->index++;
        }
    }
public:
    Converter(std::string input){
        this->infix = input;
        this->eval = new Stack<char>();
        this->operands = new Stack<char>();
        this->operators = new Stack<char>();
        convert();
    }
    ~Converter(){
        delete(this->operands);
        delete(this->operators);
        delete(this->eval);
    }
    void printStacks(){
        std::cout << "Operands\n";
        this->operands->print();
        std::cout << "Operators\n";
        this->operators->print();
        std::cout << "Eval\n";
        this->eval->print();
    }

};

#endif
