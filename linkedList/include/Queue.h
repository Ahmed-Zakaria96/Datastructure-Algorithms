#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include "Employee.h"

class Queue : private LinkedList
{
    public:
        Queue();

        void enQueue(Employee* e);
        Employee* deQueue();
        Employee* searchQ(int c);
        int deleteQ(int c);
        void displayAll();
        void freeQ();
};

#endif // QUEUE_H
