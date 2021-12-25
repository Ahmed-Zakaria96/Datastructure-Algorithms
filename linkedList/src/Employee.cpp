#include "Employee.h"
#include <string.h>
#include <iostream>
#include "colors.h"

using namespace std;

Employee::Employee()
{
    ConsoleColor C;
    C.LPurple();
    setCode();

    char* i;
    cout << "Enter Employee name: ";
    cin>>i;

    setName(i);
    setSalary();
    pNext = NULL;
    pPrevious = NULL;
}
Employee::Employee(int c)
{
    code = c;
}
Employee::Employee(int c, float s)
{
    code = c;
    salary = s;
}
Employee::Employee(int c, float s, char n[])
{
    code = c;
    salary = s;
    strcpy(name, n);
}
Employee::~Employee()
{
    delete(name);
}
//setters
void Employee::setCode()
{
    cout << "Enter Employee Code: ";
    cin>>code;
}
void Employee::setSalary()
{
    cout << "Enter Employee salary: ";
    cin>>salary;

}
void Employee::setName(char* i)
{
    int nameSize = strlen(i);
    name = new char [nameSize+1];
    strcpy(name, i);
}

int Employee::getCode()
{
    return code;
}
float Employee::getSalary()
{
    return salary;
}
char* Employee::getName()
{
    return name;
}
void Employee::printEmp()
{
    ConsoleColor C;
    C.Green();
    cout << "Employee Code: "<< code << endl;
    cout << "Employee Name: "<<name << endl;
    cout << "Employee Salary: "<<salary << endl;
    cout<<"\n"<<endl;
}
// pointers
void Employee::setPNext(Employee* e)
{
    pNext = e;
}
void Employee::setPPrevious(Employee* e)
{
    pPrevious = e;
}

Employee* Employee::getPNext()
{
    return pNext;
}
Employee* Employee::getPPrevious()
{
    return pPrevious;
}
