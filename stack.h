/***************************************************************************
Name: Natalia Ksenz
Coding 04
Purpose: The assignment to create a stack object that will work with a struct
data type called Data.

File: stack.h
***************************************************************************/

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"

class Stack {

public:

    Stack(int);
    ~Stack();

    void setSize(int);
    bool push(int, string&);
    int pop(Data&);
    int peek();
    bool isEmpty();

private:

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;   // a stack of pointer to Data
};

#endif //STACK_H
