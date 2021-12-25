#include "BinaryTree.h"
#include <cstddef>
#include "Employee.h"
#include <iostream>
#include "colors.h"

using namespace std;

BinaryTree::BinaryTree()
{
    pParent = NULL;
}

BinaryTree::~BinaryTree()
{
    //dtor
}

// inOrder Traverse
void BinaryTree::inOrder(Employee* r)
{
    if(r)
    {
        inOrder(r->getPLeft());
        r->printEmp();
        inOrder(r->getPRight());
    }

}
// helper for inOrder
void BinaryTree::inOrderTraverse()
{
    ConsoleColor C;
    C.Blue();
    cout<<"InOrderTraverse"<<endl;
    inOrder(pParent);
    cout<<endl;
}

// preOrder Traverse
void BinaryTree::preOrder(Employee* r)
{
    if(r)
    {
        r->printEmp();
        preOrder(r->getPLeft());
        preOrder(r->getPRight());
    }

}

// helper for preOrder
void BinaryTree::preOrderTraverse()
{
    ConsoleColor C;
    C.Blue();
    cout<<"PreOrderTraverse"<<endl;
    preOrder(pParent);
    cout<<endl;
}

// postOrder Traverse
void BinaryTree::postOrder(Employee* r)
{
    if (r)
    {
        postOrder(r->getPLeft());
        postOrder(r->getPRight());
        r->printEmp();
    }

}

// helper for postOrder
void BinaryTree::postOrderTraverse()
{
    ConsoleColor C;
    C.Blue();
    cout<<"PostOrderTraverse"<<endl;
    postOrder(pParent);
    cout<<endl;
}


//insert
Employee* BinaryTree::callInsert(Employee* r, Employee* e)
{
    if (r == NULL)
    {
        e->setPRight(NULL);
        e->setPLeft(NULL);
        return e;
    } else {
        if (e->getCode() <= r->getCode())
        {
            r->pLeft = callInsert(r->pLeft, e);
        } else {
            r->pRight = callInsert(r->pRight, e);
        }
        return r;
    }
}

// helper function for insert
void BinaryTree::insertNode(Employee* e)
{
    pParent = callInsert(pParent, e);
}

// search
Employee* BinaryTree::searchTree(int c)
{
    Employee* cursor;
    cursor = pParent;
    while (cursor && cursor->getCode() != c)
    {
        if (c < cursor->getCode())
        {
            cursor = cursor->pLeft;
        } else {
            cursor = cursor->pRight;
        }
    }
    return cursor;
}

int BinaryTree::treeHeight(Employee* e)
{
    if(e == NULL)
    {
        return 0;
    } else {
        int lDepth = treeHeight(e->getPLeft());
        int rDepth = treeHeight(e->getPRight());

        if (lDepth > rDepth)
        {
            return (lDepth+1);
        } else {
            return (rDepth +1);
        }
    }
}
void BinaryTree::callTreeHeight()
{
    int height = treeHeight(pParent);
    cout << "Tree height is: "<<height<<endl;
}
int BinaryTree::deleteNode(int c)
{
    Employee* cursor;
    cursor = pParent;

    // 1 element tree
    if (pParent && !cursor->getPLeft() && !cursor->getPRight())
    {
        if (cursor->getCode() == c)
        {
            pParent = NULL;
            return 1;
        } else {
            cout<<"Not Found"<<endl;
            return 0;
        }
    } else if (pParent && (cursor->getPLeft() || cursor->getPRight())) //multiple element tree
    {
        // if the element is the root of the tree
        if (pParent->getCode() == c)
        {
            // largest node in the left sub tree
            Employee* largest;
            // previous node of the largest node
            Employee* previous;
            // get the largest node in the left subtree
            largest = findLargest(pParent->getPLeft());
            // find its previous node
            previous = findPrevious(pParent, largest->getCode());
            // check if the previous element is the root
            if (previous == pParent)
            {
                // if yes set the right arm to be the right arm of the root
                largest->setPRight(pParent->getPRight());
                // set the largest as the new tree root
                pParent = largest;
                return 1;
            } else {
                // if the previous not the root
                // set its right arm to root right arm
                largest->setPRight(pParent->getPRight());
                // set its left arm to root left arm
                largest->setPLeft(pParent->getPLeft());
                // set the previous node arm to null "deleted"
                previous->setPRight(NULL);
                // set the new tree root
                pParent = largest;
                return 1;
            }
        }
        // if the node is not the root
        // find its previous
        Employee* previous = findPrevious(cursor, c);
        Employee* node;
        // if the element is found
        if (previous)
        {
            if (previous->getCode() < c)
            {
                // if the node is > previous set node to equal his right arm
                node = previous->getPRight();
            } else {
                // if the node is <= previous set node to equal his left arm
                node = previous->getPLeft();
            }
            // if the node has 2 sub trees
            if (node->getPRight() && node->getPLeft())
            {
                // find largest element in the left sub tree
                Employee* largest = findLargest(node->getPLeft());
                // set largest element right arm to equal node right arm
                largest->setPRight(node->getPRight());
                Employee* largestPrevious;
                if (largest)
                {
                    largestPrevious = findPrevious(pParent, largest->getCode());
                }
                // if node > previous
                if (largest->getCode() > previous->getCode())
                {
                    // set previous right arm to largest "new node to replace deleted one"
                    previous->setPRight(largest);
                } else {
                    // else set previous left arm to largest "new node to replace deleted one"
                    previous->setPLeft(largest);
                }
                // set largest node previous right arm to null
                largestPrevious->setPRight(NULL);
                return 1;
            // else if the node has 1 sub tree "if both or are true 2 sub trees will be handled in the previous if"
            // how to implement ^ XOR
            } else if (node->getPRight()->getCode() ^ node->getPLeft()->getCode())
            {
                // if c > previous node
                if (c > previous->getCode())
                {
                    if (previous->getPRight()->getPRight() == NULL)
                    {
                        // set previous right to null
                        previous->setPRight(NULL);
                        return 1;
                    } else {
                        // set previous right arm to element right
                        previous->setPRight(previous->getPRight()->getPRight());
                        return 1;
                    }

                } else {
                    if (previous->getPLeft()->getPLeft() == NULL)
                    {
                        previous->setPLeft(NULL);
                        return 1;
                    }else {
                        previous->setPLeft(previous->getPLeft()->getPLeft());
                        return 1;
                    }
                }
            } else {
                if (node->getCode() > previous->getCode())
                {
                    previous->setPRight(NULL);
                    return 1;
                }else {
                    previous->setPLeft(NULL);
                    return 1;
                }
            }
        } else {
            return 0;
        }
    }
}
// check if the element exists and bring the previous element to it
Employee* BinaryTree::findPrevious(Employee* r, int c)
{
    Employee* cursor;
    cursor = r;
    // search the tree for the element
    while(cursor)
    {
        //this condition will look for node from the previous level
        // if c > employee code go right
        if ( c > cursor->getCode())
        {
            if (cursor->getPRight()->getCode() == c)
            {
                // if found return cursor
                return cursor;
            } else {
                // else keep going
                cursor = cursor->getPRight();
                findPrevious(cursor, c);
            }
        // if c < employee code go left
        } else {
            if (cursor->getPLeft()->getCode() == c)
            {
                // if found return cursor
                return cursor;
            } else {
                // else keep going
                cursor = cursor->getPLeft();
                findPrevious(cursor, c);
            }
        }
    }
    return cursor;
}


Employee* BinaryTree::findLargest(Employee* node)
{
    // node is the left element of the element to be deleted
    // cursor temp pointer to search the tree with
    Employee* cursor;
    cursor = node;
    int flag = 1;
    // while there is a right for the node set cursor to node right until null
    //if u get null then it is the largest element
    while (flag)
    {
        if (cursor->getPRight())
        {
            cursor = cursor->getPRight();
        } else {
            flag = 0;
        }
    }

    return cursor;
}






