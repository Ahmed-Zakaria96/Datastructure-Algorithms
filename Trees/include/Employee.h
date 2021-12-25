#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    char* name;
    float salary;
    int code;


    public:
        Employee* pRight;
        Employee* pLeft;
        Employee();
        Employee(int c);
        Employee(int c, float s);
        Employee(int c, float s, char n[]);

        ~Employee();

        // setters
        void setCode();
        void setSalary();
        void setName(char* i);
        void setPRight(Employee* e);
        void setPLeft(Employee* e);

        //getters
        int getCode();
        float getSalary();
        char* getName();
        Employee* getPRight();
        Employee* getPLeft();

        void printEmp();
};

#endif // EMPLOYEE_H
