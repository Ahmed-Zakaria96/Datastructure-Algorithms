#include <iostream>
#include "Employee.h"
#include "BinaryTree.h"
#include "colors.h"

using namespace std;

int main()
{
    cout<< "\nWELCOME TO BINARY TREE PROGRAM\n\n\n" <<endl;
    ConsoleColor C;
    Employee e1(50, 1.1, "Simple-Z");
    Employee e2(40, 2.2, "Ahmed");
    Employee e3(60, 3.3, "Zakaria");
    Employee e4(30, 4.4, "Ali");
    Employee e5(45, 5.5, "Ahmed");
    Employee e6(43, 6.6, "Yoused");
    Employee e7(46, 7.7, "nope");
    Employee e8(70, 8.8, "nope");

    BinaryTree b;
    b.insertNode(&e1);
    b.insertNode(&e2);
    b.insertNode(&e3);
    b.insertNode(&e4);
    b.insertNode(&e5);
    b.insertNode(&e6);
    b.insertNode(&e7);
    b.insertNode(&e8);

    b.callTreeHeight();
    b.searchTree(40);
    b.inOrderTraverse();
    b.preOrderTraverse();
    b.postOrderTraverse();
    b.deleteNode(40);
    cout<<"After delete"<<endl;
    b.inOrderTraverse();
    b.preOrderTraverse();
    b.postOrderTraverse();
    b.callTreeHeight();
    return 0;
}

