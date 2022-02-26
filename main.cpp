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
        if (isdigit(*argv[1])) {
            int size = atoi(argv[1]);
            if (size < 2) {
                cout << "Error: You need to input the program name and ONE integer with" <<
                " value greater than 2.\nThe program will be terminted." << endl;
            }
            else {
                cout << "Creating stack of size " << size << endl;
                Stack stack(size);

                /************************************************
                ******* EMPTY TESTS *****************************
                ************************************************/

                cout << "\nBeginning tests...\n\nTesting empty operations." << endl;
                cout << "=====================================================" << endl;

                // testing isEmpty() on empty stack
                if (stack.isEmpty()){
                    cout << "The stack is empty" << endl;
                }
                else {
                    cout << "The stack is not empty" << endl;
                }
                cout << endl;

                Data *data = new Data; // empty struct for testing
                // testing peek()
                if(stack.peek(data)){
                    cout << "Id: " << data->id << " and information: " <<
                    data->information << " peeked from the stack" << endl;
                }
                else {
                    cout << "Peek underflow error: stack is empty" << endl;
                }
                cout << endl;

                // testing pop()
                if(stack.pop(data)) {
                    cout << "Id: " << data->id << " and information: " <<
                    data->information << " popped from the stack" << endl;
                }
                else{
                    cout << "Pop underflow error: stack is empty" << endl;
                }

                cout << "\nTesting full operations." << endl;
                cout << "=====================================================" << endl;

                // testing filling the stack and overflow
                cout << "Filling stack..." << endl;
                for (int i = 0; i < size*MULTIPLIER; i++) {
                    int num=rand()%1000;
                    std::string strtemp;
                    rand_string(&strtemp);
                    if (stack.push(num, strtemp)) {
                        cout << "Pushed id: " << num << " information: " << strtemp << endl;
                    } else {
                        cout << "Error: data was not pushed" << endl;
                    }
                }
                cout << endl;

                // testing isEmpty() on full stack
                if (stack.isEmpty()) {
                    cout << "The stack is empty" << endl;
                } else {
                    cout << "The stack is not empty" << endl;
                }
                cout << endl;

                // testing peek() and pop() on full stack
                if(stack.peek(data)) {
                    cout << "Id: " << data->id << " and information: " <<
                    data->information << " peeked from the stack" << endl;
                } else {
                    cout << "Peek underflow error: stack is empty" << endl;
                }

                if(stack.pop(data)) {
                    cout << "Id: " << data->id << " and information: " <<
                    data->information << " popped from the stack" << endl;
                }
                else{
                    cout << "Pop underflow error: stack is empty" << endl;
                }
                cout << endl;

                cout << "Testing peek and pop, and emptying stack..." << endl;
                cout << "=====================================================" << endl;

                // testing popping and peeking whole stack
                for (int i = 0; i < size*MULTIPLIER; i++) {
                    if(stack.peek(data)){
                        cout << "Id: " << data->id << " and information: " <<
                        data->information << " peeked from the stack" << endl;
                    } else {
                        cout << "Peek underflow error: stack is empty" << endl;
                    }

                    if(stack.pop(data)) {
                        cout << "Id: " << data->id << " and information: " <<
                        data->information << " popped from the stack" << endl;
                    }
                    else{
                        cout << "Pop underflow error: stack is empty" << endl;
                    }
                    cout << endl;
                }

                // testing isEmpty() on empty stack
                if (stack.isEmpty()) {
                    cout << "The stack is empty" << endl;
                } else {
                    cout << "The stack is not empty" << endl;
                }
                cout << endl;

                // testing peek() and pop() on empty stack
                if(stack.peek(data)){
                    cout << "Id: " << data->id << " and information: " <<
                    data->information << " peeked from the stack" << endl;
                }
                else {
                    cout << "Peek underflow error: stack is empty" << endl;
                }

                if(stack.pop(data)) {
                    cout << "Id: " << data->id << " and information: " <<
                    data->information << " popped from the stack" << endl;
                }
                else{
                    cout << "Pop underflow error: stack is empty" << endl;
                }
                cout << endl;

                /************************************************
                ******** MID-STACK TESTS ************************
                ************************************************/

                cout << "Filling stack halfway and testing the middle of the stack..." << endl;
                cout << "============================================================" << endl;
                // filling the stack half way to test the middle of the stack
                for (int i = 0; i < int(size / 2); i++) {
                    int num=rand()%1000;
                    std::string strtemp;
                    rand_string(&strtemp);
                    if (stack.push(num, strtemp)) {
                        cout << "pushed id: " << num << " information: " << strtemp << endl;
                    } else {
                        cout << "Error: data was not pushed" << endl;
                    }
                }
                cout << endl;

                // testing middle in a narrow band
                for (int i = 0; i < int(size * NARROW); i++) {
                    if (stack.isEmpty()) {
                        cout << "The stack is empty" << endl;
                    } else {
                      cout << "The stack is not empty" << endl;
                    }
                    cout << endl;

                    // testing peek() and pop() on empty stack
                    if(stack.peek(data)){
                        cout << "Id: " << data->id << " and information: " <<
                        data->information << " peeked from the stack" << endl;
                    }
                    else {
                        cout << "Peek underflow error: stack is empty" << endl;
                    }

                    if(stack.pop(data)) {
                        cout << "Id: " << data->id << " and information: " <<
                        data->information << " popped from the stack" << endl;
                    }
                    else{
                        cout << "Pop underflow error: stack is empty" << endl;
                    }

                    int num=rand()%1000;
                    std::string strtemp;
                    rand_string(&strtemp);
                    if (stack.push(num, strtemp)) {
                        cout << "Pushed id: " << num << " information: " << strtemp << endl;
                    } else {
                        cout << "Error: data was not pushed" << endl;
                    }
                }
                cout << endl;

                /************************************************
                ******** RANDOM TESTS ***************************
                ************************************************/

                cout << "Random testing..." << endl;
                cout << "============================================================" << endl;
                // clearing stack to start
                while(!stack.isEmpty()){
                    stack.pop(data);
                }

                // filling the stack half way with random numbers to begin random tests
                for (int i = 0; i< int(size / 2); i++) {
                    int num=rand()%1000;
                    std::string strtemp;
                    rand_string(&strtemp);
                    if (stack.push(num, strtemp)) {
                        cout << "pushed id: " << num << " information: " << strtemp << endl;
                    } else {
                        cout << "Error: data was not pushed" << endl;
                    }
                }

                // testing random operations
                for (int test=0; test<=size+30; test++) {
                    int option = rand()%6;
                    int num=rand()%1000;
                    std::string strtemp;
                    rand_string(&strtemp);

                    switch(option) {
                        case 0:
                        case 1:
                            // push()
                            if (stack.push(num, strtemp)) {
                                cout << "Pushed id: " << num << " information: " <<
                                strtemp << endl;
                            } else {
                                cout << "Error: data was not pushed" << endl;
                            }
                            break;

                        case 2:
                        case 3:
                            // pop()
                            if(stack.pop(data)) {
                                cout << "Id: " << data->id << " and information: " <<
                                data->information << " popped from the stack" << endl;
                            }
                            else{
                                cout << "Pop underflow error: stack is empty" << endl;
                            }
                            break;

                        case 4:
                            // peek()
                            if(stack.peek(data)){
                                cout << "Id: " << data->id << " and information: " <<
                                data->information << " peeked from the stack" << endl;
                            }
                            else {
                                cout << "Peek underflow error: stack is empty" << endl;
                            }
                            break;

                        case 5:
                        // isEmpty()
                            if (stack.isEmpty()) {
                                cout << "The stack is empty" << endl;
                            }
                            else {
                                cout << "The stack is not empty" << endl;
                            }
                            break;
                    }
                }
                cout << endl;
                cout << "Testing complete." << endl;
            }
        }
        else {
            cout << "Error: You need to input the program name and ONE integer with" <<
            " value greater than 2.\nThe program will be terminted." << endl;
        }
    }
    return 0;
}
