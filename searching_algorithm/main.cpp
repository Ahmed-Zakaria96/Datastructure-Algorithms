#include <iostream>
#include "Employee.h"
#include "EmployeeSort.h"
#include "colors.h"
#include <conio.h>

using namespace std;

//helper functions
void display();
void display2ndMenu(EmployeeSort* es);
void searchMenu(EmployeeSort* es);
void algorithmMenu(EmployeeSort* es);

int main()
{
    //Console color class for manipulating output colors
    //Program definition and instructions
    ConsoleColor C;
    cout << "\n\n\t\tWELCOME TO SORTING ALGORITHMS PROGRAM\n\n" <<endl;
    C.Purple();
    cout << "Instructions"<<endl;
    C.Grey();
    cout << "1- You will be asked to enter the number of elements in the array.\n";
    cout << "2- You will be prompt to fill each element data.\n";
    cout << "3- Then you can choose from sorting algorithm menu.\n"<<endl;

    // display menu to user
    display();
}

void display()
{
    ConsoleColor C;
    // create object of class Employee sort
    // the default constructor will prompt user to fill its data
    EmployeeSort emp;
    EmployeeSort* es= &emp;
    int select;
    system("CLS");
    C.LWhite();
    cout << "1- Search Menu"<< endl;
    cout << "2- Algorithm Menu" << endl;
    C.Blue();
    cout<<"Please choose an option: ";
    cin>> select;
    switch(select)
    {
    case 1:
        searchMenu(es);
        break;
    case 2:
        algorithmMenu(es);
        break;
    }

}
void searchMenu(EmployeeSort* es)
{
    system("CLS");
    ConsoleColor C;
    C.LWhite();
    cout<<"1- Search for Employee using linear search"<<endl;
    cout<<"2- Search for Employee using binary search"<<endl;
    cout<<"3- Sorting algorithm Menu"<< endl;
    C.Blue();
    cout << "Choose an option"<<endl;
    int selection;
    cin>> selection;
    switch(selection)
    {
        case 1:
            es->seqSearch();
            break;
        case 2:
            if(es->getSortedStatus())
            {
                es->binarySearch();
                break;
            } else {
                C.Red();
                cout<<"Array not sorted consider sorting first before binary search."<<endl;
                system("Pause");
                algorithmMenu(es);
                break;
            }

        case 3:
            algorithmMenu(es);
            break;
    }
}
void algorithmMenu(EmployeeSort* es)
{
    ConsoleColor C;
    C.Purple();
    //after user finish his data entry clear screen and show selection option
    system("CLS");
    cout<<"Available sorting algorithms: "<<endl;
    C.LWhite();
    cout<<"1- Selection Sort"<<endl;
    cout<<"2- Insertion Sort"<<endl;
    cout<<"3- Bubble Sort"<<endl;
    cout<<"4- Merge Sort"<<endl;
    cout<<"5- Quick Sort"<<endl;
    cout<<"6- Search Menu"<<endl;

    //variable to take user input in it
    int select;
    C.Blue();
    cout << "Enter Your desired algorithm: ";
    cin >> select;
    //switch user select with appropriate sorting algorithm
    switch(select)
    {
        case 1:
            es->selectionSort();
            break;
        case 2:
            es->insertionSort();
            break;
        case 3:
            es->bubbleSort();
            break;
        case 4:
            es->callMerge();
            break;
        case 5:
            es->CallQuick();
            break;
        case 6:
            system("CLS");
            searchMenu(es);
            break;
    }
    //after performing algorithm display sub menu to user
    display2ndMenu(es);
}
// contain display sorted array option or another sorting action or exit
void display2ndMenu(EmployeeSort* es)
{
    ConsoleColor C;
    cout<<"1- Display sorted array"<<endl;
    cout<<"2- Sort another array"<<endl;
    cout<<"3- Search for another employee"<<endl;
    cout<<"4- Exit!"<<endl;

    // variable to store user selection
    int select;
    C.Blue();
    //switch user selection for an action
    cout << "Enter action: ";
    cin >> select;
    switch(select)
    {
        case 1:
            //display sorted array
            es->printSortedEmps();
            C.Grey();
            //wait for user to decide if he want to sort another array or exit
            cout <<"Press any key sort another array or ESC to exit"<<endl;
            char ch;
            ch = getch();
            if (ch != 27)// !escape key
            {
                system("CLS");
                algorithmMenu(es);

            } else
            {
                C.LWhite();
                cout << "Thanks for using our program" << endl;
                cout << "Exiting...." <<endl;
                return;
            }
            break;
        case 2:
            algorithmMenu(es);
            break;
        case 3:
            searchMenu(es);
        case 4:
            return;

    }
}
