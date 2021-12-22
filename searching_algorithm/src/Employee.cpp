#include "Employee.h"
#include <string.h>
#include <iostream>
using namespace std;

//default constructor
Employee::Employee()
{
    id = 0;
    salary = 0;
}
// 1 parameter constructor
Employee::Employee(int empID)
{
    id = empID;
    salary = 0;
}

// 2 parameter constructor
Employee::Employee(int empID, int empSalary)
{

    id = empID;
    salary = empSalary;
}

//copy constructor
Employee::Employee(Employee& emp)
{
    //ctor
    id = emp.id;
    salary = emp.salary;
}

Employee::~Employee()
{
    //dtor
}

//setters
void Employee::setEmpID(){
    cout<<"Enter Employee id: ";
    cin>>id;
}

void Employee::setEmpSalary(){
    cout<<"Enter Employee salary: ";
    cin>>salary;
}

//getters
int Employee::getEmpID(){
    return id;
}

int Employee::getEmpSalary(){
    return salary;
}

void Employee::printEmp()
{
    cout << "ID "<< getEmpID() <<endl;
    cout << "Salary "<<getEmpSalary() <<endl;
}

//operator overloading
void Employee::operator=(Employee e){
    id = e.id;
    salary = e.salary;
}


