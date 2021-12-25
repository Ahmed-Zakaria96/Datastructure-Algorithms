#include "Stack.h"
#include <cstddef>
Stack::Stack()
{
    //ctor
}

void Stack::push(Employee* e)
{
    addList(e);
}
Employee* Stack::pop()
{
    Employee* cursor;
    if (pStart)
    {
       if (pStart == pEnd)
        {
            cursor = pEnd;
            pStart=pEnd=NULL;
        } else {
            cursor = pEnd;
            pEnd = pEnd->pPrevious;
            pEnd->pNext = NULL;
        }
    }

    return cursor;
}
Employee* Stack::searchS(int c)
{
    return searchList(c);
}
int Stack::deleteS(int c)
{
    return deleteList(c);
}
void Stack::displayAll()
{
    LinkedList::displayAll();
}

void Stack::freeS()
{
    freeList();
}
