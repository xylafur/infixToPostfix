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
    //step thats called after processing a character.  Flushes the
    // operator/ operand stacks if it is needed
    void checkStacks(){
        //if either is empty don't even bother yet
        if(operands->isEmpty() || operators->isEmpty() )
            return;
        if(operands->size() >= 2){
            char temp = operands->pop();
            eval->push(operands->pop());
            eval->push(temp);
            if(parenthesisLevel == 0 && operators->size() > 0)
                eval->push(operators->pop());
        }
    }
    //called at the very end of conversion.  Flushes everything out of the
    // stacks into the final string
    void flush(){
        while(!operands->isEmpty())
            eval->push(operands->pop());
        while(!operators->isEmpty()){
            char temp = operators->pop();
            if(temp!='(' && temp!=')')
                eval->push(temp);
        }
    }
    //grabs the next character from the string and processes it
    void processCurrentChar(){
        Type charType = defineCharacter();
        if(charType == operand)
            this->operands->push(infix.at(index));
        else if(charType == operat)
            this->operators->push(infix.at(index));
        checkStacks();
    }
    //final step.  Takes the eval stack and turns it into the proper postfix
    // string
    void stackToString(){
        std::string str = "";
        while(!eval->isEmpty())
            str = eval->pop() + str;
        this->postfix = str;
    }
    //function to convert infix string to postfix string
    void convert(){
        while(index < infix.length()){
            processCurrentChar();
            this->index++;
        }
        flush();
        stackToString();
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
    void print(){
        std::cout<<this->postfix<<std::endl;
    }

};

#endif
