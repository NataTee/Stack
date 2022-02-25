/***************************************************************************
Name: Natalia Ksenz
Coding 04
Purpose: The assignment to create a stack object that will work with a struct
data type called Data.

File: main.cpp
***************************************************************************/

#include "main.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc != 2) {
        cout << "Error: You need to input the program name and ONE integer with" <<
        " value greater than 2.\nThe program will be terminted." << endl;
    }
    else {
        int size = atoi(argv[1]);
        if (size < 2) {
            cout << "Error: You need to input the program name and ONE integer with" <<
            " value greater than 2.\nThe program will be terminted." << endl;
        }
        else {
            Stack stack(size);

            cout << "\nBeginning tests...\n\nTesting empty operations." << endl;
            cout << "=====================================================" << endl;

            // testing isEmpty() on empty stack
            if (stack.isEmpty()){
                cout << "The stack is empty." << endl;
            }
            else {
                cout << "The stack is not empty." << endl;
            }

            // testing peek()
            /*if()){
                cout << "Id: " << data->id << " and information: " << data->information <<
                "peeked from the stack" << endl;
            } else {
                cout << "Peek underflow error: stack is empty" << endl;
            }*/

            // testing pop()
            Data *data = new Data;
            if(stack.pop(data)) {
                cout << "Id: " << data->id << " and information: " << data->information <<
                "popped from the stack" << endl;
            }
            else{
                cout << "Pop underflow error: stack is empty" << endl;
            }
                cout << endl;


            cout << "\nTesting full operations." << endl;
            cout << "=====================================================" << endl;

            // testing filling the stack and overflow
            cout << "Filling stack..." << endl;
            for (int i = 0; i < size*MULTIPLIER; i++) {
                int num1=rand()%1000;
                std::string strtemp;
                rand_string(&strtemp);
                if (stack.push(num1, strtemp)) {
                    cout << "pushed id: " << num1 << " information: " << strtemp << endl;
                } else {
                    cout << "overflow error: " << num1  << " and " << strtemp <<
                    " not pushed" << endl;
                }
            }
            cout << endl;

        }
    }
    return 0;
}
