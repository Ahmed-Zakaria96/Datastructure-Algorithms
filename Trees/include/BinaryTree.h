#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Employee.h"

class BinaryTree
{
    Employee* pParent;

    // helper methods
    Employee* callInsert(Employee* r, Employee* e);

    void inOrder(Employee* r);
    void preOrder(Employee* r);
    void postOrder(Employee* r);

    public:
        BinaryTree();
        ~BinaryTree();

        //insert
        void insertNode(Employee* e);

        // search
        Employee* searchTree(int c);

        //traverse
        void inOrderTraverse();
        void preOrderTraverse();
        void postOrderTraverse();

        //bouns
        //delete node
        Employee* findPrevious(Employee* r, int c);
        Employee* findLargest(Employee* node);
        int deleteNode(int c);

        //tree height
        int treeHeight(Employee* e);
        void callTreeHeight();


};

#endif // BINARYTREE_H
