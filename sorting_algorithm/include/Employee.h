#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    //data
    int id;
    int salary;

    //methods
    public:
    void setEmpID();
    void setEmpSalary();

    int getEmpID();
    int getEmpSalary();

    //constructors
    //default
    Employee();
    //1 parameter constructor
    Employee(int empID);
    //2 parameters
    Employee(int empID, int empSalary);

    //Destructor
    ~Employee();

    // copy constructor
    Employee(Employee& emp);

    //operator overloading
    void operator=(Employee e);

};

#endif // EMPLOYEE_H
