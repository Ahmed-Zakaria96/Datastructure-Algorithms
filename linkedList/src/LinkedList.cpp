#include "LinkedList.h"
#include <cstddef>

LinkedList::LinkedList()
{
    pStart = pEnd = NULL;
}

void LinkedList::setPStart(Employee* e)
{
    pStart = e;
}

void LinkedList::setPEnd(Employee* e)
{
    pEnd = e;
}

Employee* LinkedList::getPStart()
{
    return pStart;
}
Employee* LinkedList::getPEnd()
{
    return pEnd;
}

void LinkedList::addList(Employee* e)
{
    if (!pStart)
    {
        e->pNext = NULL;
        e->pPrevious = NULL;
        pStart = pEnd = e;
    } else
    {
        pEnd->pNext = e;
        e->pPrevious = pEnd;
        e->pNext = NULL;
        pEnd = e;
    }
}

Employee* LinkedList::searchList(int k)
{
    Employee* cursor;
    cursor = pStart;
    while(cursor && cursor->getCode() != k)
    {
        cursor = cursor->pNext;
    }
    return cursor;
}
void LinkedList::insertList(Employee* e)
{
    Employee* cursor;
    if (pStart == NULL)
    {
        addList(e);
    } else {
        cursor = pStart;
        while(cursor && (cursor->getCode() < e->getCode()))
        {
            cursor = cursor->pNext;
        }
        if(!cursor)
        {
            addList(e);

        }else if(cursor == pStart)
        {
            e->pNext = pStart;
            e->pPrevious = NULL;
            pStart->pPrevious = e;
            pStart = e;
        } else {
            e->pNext = cursor;
            e->pPrevious = cursor->pPrevious;
            cursor->pPrevious->pNext = e;
            cursor->pPrevious = e;

        }
    }
}

int LinkedList::deleteList(int c)
{
    Employee* cursor;
    int flag = 1;
    cursor = searchList(c);
    if (!cursor)
    {
        flag = 0;
    } else {
        if (pStart == pEnd)
        {
            delete(pStart);
            pStart = pEnd = NULL;
        } else if (cursor == pStart)
        {
            pStart = pStart->pNext;
            delete(pStart->pPrevious);
            pStart->pPrevious = NULL;
        } else if (cursor == pEnd)
        {
            pEnd = pEnd->pPrevious;
            delete(pEnd->pNext);
            pEnd->pNext = NULL;
        }else {
            cursor->pPrevious->pNext = cursor->pNext;
            cursor->pNext->pPrevious = cursor->pPrevious;
            delete(cursor);
        }
    }

    return flag;
}

void LinkedList::freeList()
{
    Employee* cursor;
    while(pStart)
    {
        cursor = pStart;
        pStart = pStart->pNext;
        delete(cursor);
    }
    pEnd = NULL;
}

void LinkedList::displayAll()
{
    Employee* cursor;
    cursor = pStart;
    while (cursor != NULL)
    {
        cursor->printEmp();
        cursor = cursor->pNext;
    }
}

// pop
Employee LinkedList::pop()
{
    Employee temp = *pStart;
    pStart = pStart->pNext;
    pStart->pPrevious = NULL;
    return temp;
}
Employee LinkedList::lastPop()
{
    Employee temp = *pEnd;
    pEnd = pEnd->pPrevious;
    pEnd->pNext = NULL;
    return temp;
}
