#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Employee.h"

class LinkedList
{
    protected:
        Employee* pStart;
        Employee* pEnd;

    public:
        LinkedList();

        void setPStart(Employee* e);
        void setPEnd(Employee* e);

        Employee* getPStart();
        Employee* getPEnd();

        void addList(Employee* e);
        void insertList(Employee* e);
        Employee* searchList(int k);
        int deleteList(int c);
        void freeList();
        void displayAll();

        Employee pop();
        Employee lastPop();
};

#endif // LINKEDLIST_H
