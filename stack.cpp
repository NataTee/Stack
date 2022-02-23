/***************************************************************************
Name: Natalia Ksenz
Coding 04
Purpose: The assignment to create a stack object that will work with a struct
data type called Data.

File: stack.cpp
***************************************************************************/

// each cpp includes ONLY it's header directly
#include "stack.h"

Stack::Stack(int s) {
    top = -1;
    setSize(s);
    stack = new Data*[size];
}


Stack::~Stack() {
}

bool Stack::push(int id, string &infoString) {
  bool add = true;

  if (top < size-1) {
      if (id > 0 && infoString != "\0") {
          Data *data = new Data;
          data->id = id;
          data->information = infoString;
          stack[++top] = data;
      }
      else {
          add = false;
      }
  }
  else {
      add = false;
  }

  return add;
}

bool Stack::pop(&data) {

    if (isEmpty()) {
        throw "Underflow error!";
    }
    return stack[top--];
}

bool Stack::peek() {
    if (isEmpty()) {
        throw "Stack is empty!";
    }
    return stack[top];
}

bool Stack::isEmpty() {
  bool empty = false;
  if(top == -1) {
      empty = true;
  }
  return empty;
}

void Stack::setSize (int s) {
    if (s > 2) {
        size = s;
    }
    else {
      size = 2;
    }
}
