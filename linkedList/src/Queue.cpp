#include "Queue.h"
#include <cstddef>

Queue::Queue()
{
    //ctor
}

void Queue::enQueue(Employee* e)
{
    addList(e);
}
Employee* Queue::deQueue()
{
    Employee* cursor;
    cursor = pStart;
    if (pStart)
    {
        if (pStart==pEnd)
        {
            pStart = pEnd = NULL;
        } else {
            pStart = pStart->pNext;
            pStart->pPrevious = NULL;
        }
    }
    return cursor;
}
Employee* Queue::searchQ(int c)
{
    return searchList(c);
}
int Queue::deleteQ(int c)
{
    return deleteList(c);
}
void Queue::displayAll()
{
    LinkedList::displayAll();
}
void Queue::freeQ()
{
    freeList();
}
