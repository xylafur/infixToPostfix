#ifndef POSTFIX_CONVERTER
    #define POSTFIX_CONVERTER
#include <string>
#include "stack.h"
#include <iostream>
#include <stdio.h>
//there are only 3 possible types each char can be
enum Type {Operator, Operand, Space};
class Converter{
    /*
     *  Steps:
     *      Go through input string and process each character individually.
     *      If you find an operator or operand put them in the correct stack.
     *      If you get an operator with lower presidence than the others
     *              currently in the stack, pop it off.
     *      When you find a opening parenthesis keep processing characters until
     *              you get to the closing parenthisis.  At this point, just pop
     *              everything from the closing to the opening.
     *      
     */
private:
    std::string infix, postfix;
    unsigned int index;
    int parenthDepth;
    char current;
    Stack<char> *operators, *operands, *eval;
    
    void popTillParenth(){
        /*
         *  A closing parenthesis was found, pop till the opener
         */
        if( parenthDepth < 0){printf("Boi you fucked up somewhere");return;}
        char temp = operators->pop();
        while(temp!='('){
            eval->push(temp);
            temp = operators->pop();
        }
    }
    void checkPresidence(){
        /*
         *  Checks the presidence of the current operator in relation to the
         *  others on the stack.  Will either 
         *      1) Push it to the stack if its lower presidence
         *      2) Pop off all operators until one with higher presidence is
         *              found.  Then will push the value to the stack.
         *      3) If the char is a parenthesis we need to consider which side
         *              it is
         *          If it is the closing side we pop until we get to the opening
         */
        switch(this->current){
            case '(':
                parenthDepth++;
                operators->push('(');
                break;
            case ')':
                parenthDepth--;
                popTillParenth();
                break;
            case '+':
            case '-':
                {
                if(operators->isEmpty()){operators->push(this->current);break;}
                char temp = operators->peek();
                while((temp == '*' || temp == '/')){
                    eval->push(operators->pop());
                    if(operators->isEmpty())
                        break;
                    temp = operators->peek();

                }
                operators->push(this->current);
                }
                break;
            case '*':
            case '/':
                operators->push(this->current);
                break;
            default:
                break;
        }

    }
    void handleOperand(){
        /*
         *  The current char is an operand (A, B, C, ..., etc).
         *  Either put it in the operand stack or pop them hoes off
         */
        eval->push(this->current);
    }

    Type determineType(){
        /*
         *  Uses the member variable 'current' and determines its type
         */
        switch(this->current){
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
                return Operator;
            case ' ':
                return Space;
            default:
                return Operand;
        }
        return Operand;
    }
    void flush(){
        while(!operands->isEmpty()){
            eval->push(operands->pop());
        }
        while(!operators->isEmpty())
            eval->push(operators->pop());
    }
    void processChar(){
        /*
         *  Processes the char at specified index and puts it in right stack
         */
        Type charType = determineType();
        switch(charType){
            case Operator:
                checkPresidence();
                break;
            case Operand:
                handleOperand();
                break;
            default:
                break;
        }
    }
    void stackToString(){
        std::string s = "";
        eval->print();
        while(!eval->isEmpty())
            s = eval->pop() + s;
        this->postfix = s;
    }
    void convertToPostfix(){
        while(this->index < infix.length()){
            this->current = infix.at(index);
            processChar();
            this->index++;
        }
        flush();
        stackToString();
    }
public:
    Converter(std::string in){
        this->operators = new Stack<char>();
        this->operands = new Stack<char>();
        this->eval = new Stack<char>();
       this->infix = in;
       this->index = 0;
       convertToPostfix();
    }
    void print(){
        std::cout << "printing..\n" << this->postfix << std::endl;
    }
    std::string getPostfix(){
        return this->postfix;
    }
};

#endif
