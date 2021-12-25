#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    char* name;
    float salary;
    int code;


    public:
        Employee* pNext;
        Employee* pPrevious;
        Employee();
        Employee(int c);
        Employee(int c, float s);
        Employee(int c, float s, char n[]);

        ~Employee();

        // setters
        void setCode();
        void setSalary();
        void setName(char* i);
        void setPNext(Employee* e);
        void setPPrevious(Employee* e);

        //getters
        int getCode();
        float getSalary();
        char* getName();
        Employee* getPNext();
        Employee* getPPrevious();

        void printEmp();
};

#endif // EMPLOYEE_H
