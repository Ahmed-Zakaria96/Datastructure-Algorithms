#include "Employee.h"
#include <string.h>
#include <iostream>
#include "colors.h"

using namespace std;

Employee::Employee()
{
    ConsoleColor C;
    C.Purple();
    setCode();

    char* i;
    cout << "Enter Employee name: ";
    cin>>i;

    setName(i);
    setSalary();
    pRight = NULL;
    pLeft = NULL;
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
    setName(n);
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
    C.Purple();
    cout << "Employee ";
    C.Green();
    cout<< "Code: "<< code <<" | Name: "<< name <<" | Salary: "<< salary<< endl;
}
// pointers
void Employee::setPRight(Employee* e)
{
    pRight = e;
}
void Employee::setPLeft(Employee* e)
{
    pLeft = e;
}

Employee* Employee::getPRight()
{
    return pRight;
}
Employee* Employee::getPLeft()
{
    return pLeft;
}
