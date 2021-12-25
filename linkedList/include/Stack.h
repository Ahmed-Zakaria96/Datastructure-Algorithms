#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
#include "Employee.h"

class Stack : private LinkedList
{
    public:
        Stack();


        void push(Employee* e);
        Employee* pop();
        Employee* searchS(int c);
        int deleteS(int c);
        void displayAll();
        void freeS();

};

#endif // STACK_H
