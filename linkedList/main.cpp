#include <iostream>
#include "LinkedList.h"
#include "Employee.h"
#include "colors.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

void mainMenu();
void LLMethods();
LinkedList* createLL();
void switchSelection(int m, LinkedList* l, int& f);
void LLOptions(LinkedList* ll);
void QueueMenu();
void StackMenu();
void QueueOptions();
void StackOptions();

int main()
{
    //Console color class for manipulating output colors
    //Program definition and instructions
    ConsoleColor C;
    cout << "\n\n\t\tWELCOME TO LINKED LIST PROGRAM\n\n" <<endl;
    C.Purple();
    cout << "Instructions"<<endl;
    C.Grey();
    cout << "1- You will be asked data structure type you want.\n";
    cout << "2- Each data structure has different methods.\n";
    cout << "3- Each data structure has it own sub menu for available actions.\n\n";

    C.White();
    // logic start
    mainMenu();
    C.Blue();
    int select;
    cout << "\nEnter your select: ";
    cin >> select;
    C.LWhite();
    LinkedList* ll;
    switch(select)
    {
        case 1:
            ll = createLL();
            LLMethods();
            LLOptions(ll);
            break;
        case 2:
            QueueMenu();
            QueueOptions();
            break;
        case 3:
            StackMenu();
            StackOptions();
            break;
        case 4:
            cout<<"Ana ma4y slamo 3leko......."<<endl;
            return 0;
    }
    return 0;
}
void mainMenu()
{
    cout << "1- Create a linked list.\n";
    cout << "2- Create Queue\n";
    cout << "3- Create Stack\n";
    cout << "4- Exit!. Why are you here?\n";
}
void LLOptions(LinkedList* ll)
{
    int flag = 1;
    while(flag)
    {
        int m;
        cout<<"Enter your select."<<endl;
        cin>>m;
        switchSelection(m, ll, flag);
    }

}
void LLMethods()
{
    system("CLS");
    cout << "\nLinked List Options\n\n"<<endl;
    cout << "1- Add new node." <<endl;
    cout << "2- Delete node." <<endl;
    cout << "3- Search for node." <<endl;
    cout << "4- Display all nodes." <<endl;
    cout << "5- Free node list." <<endl;
    cout << "6- Exit.\n" <<endl;
}

LinkedList* createLL()
{
    LinkedList* l;
    l = new LinkedList;
    return l;
}

void switchSelection(int m, LinkedList* l, int& f)
{
    switch(m)
    {
    case 1:
        Employee* e;
        e = new Employee;
        l->insertList(e);
        break;
    case 2:
        int d;
        cout << "Enter employee code to delete" <<endl;
        cin >>d;
        l->deleteList(d);
        break;
    case 3:
        int s;
        cout << "Enter employee code to search for" <<endl;
        cin >>s;
        if (l->searchList(s))
        {
            l->searchList(s)->printEmp();
        } else {
            cout << "Not Found"<<endl;
        }

        break;
    case 4:
        l->displayAll();
        break;
    case 5:
        l->freeList();
        break;
    case 6:
        f = 0;
        break;
    }
}


void StackMenu()
{
    system("CLS");
    cout<<"\nStack Options\n\n"<<endl;
    cout<<"1- Push node."<<endl;
    cout<<"2- Pop node."<<endl;
    cout<<"3- Search for node."<<endl;
    cout<<"4- Delete node."<<endl;
    cout<<"5- Display all nodes."<<endl;
    cout<<"6- Free nodes list."<<endl;
}

void QueueMenu()
{
    system("CLS");
    cout<<"\nQueue Options\n\n"<<endl;
    cout<<"1- EnQueue node."<<endl;
    cout<<"2- DeQueue node."<<endl;
    cout<<"3- Search for node."<<endl;
    cout<<"4- Delete node."<<endl;
    cout<<"5- Display all nodes."<<endl;
    cout<<"6- Free nodes list."<<endl;
}

void QueueOptions()
{
    ConsoleColor C;
    int flag = 1;
    Queue q;
    while(flag)
    {
        C.Blue();
        int s;
        cout<<"\nChoose an option: ";
        cin>>s;
        switch(s)
        {
            case 1:
                Employee* e;
                e = new Employee;
                q.enQueue(e);
                break;
            case 2:
                q.deQueue();
                break;
            case 3:
                int s;
                cout<<"\nEnter Employee code to search for: ";
                cin>>s;
                if (q.searchQ(s))
                {
                    q.searchQ(s)->printEmp();
                } else {
                    cout<<"Not Found"<<endl;
                }

                break;
            case 4:
                int d;
                cout<<"\nEnter Employee code to delete: ";
                cin>>d;
                q.deleteQ(d);
                break;
            case 5:
                q.displayAll();
                break;
            case 6:
                q.freeQ();
                break;
            case 7:
                flag = 0;
        }
    }

}

void StackOptions()
{
    ConsoleColor C;
    int flag = 1;
    Stack s;
    while(flag)
    {
        C.Blue();
        int o;
        cout<<"\nChoose an option: ";
        cin>>o;
        switch(o)
        {
            case 1:
                Employee* e;
                e = new Employee;
                s.push(e);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                int c;
                cout<<"\nEnter Employee code to search for: ";
                cin>>c;
                if (s.searchS(c))
                {
                    s.searchS(c)->printEmp();
                }else {
                    cout<<"Not Found"<<endl;
                }
                break;
            case 4:
                int d;
                cout<<"\nEnter Employee code to delete: ";
                cin>>d;
                s.deleteS(d);
                break;
            case 5:
                s.displayAll();
                break;
            case 6:
                s.freeS();
                break;
            case 7:
                flag = 0;
            }
    }

}







