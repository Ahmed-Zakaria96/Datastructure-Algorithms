#ifndef EMPLOYEESORT_H
#define EMPLOYEESORT_H
#include "Employee.h"

class EmployeeSort
{
    // pointer to employee object to later dynamically allocate array of emps
    Employee* emps;
    //size of the array
    int empCount;

    public:
        EmployeeSort();
        ~EmployeeSort();

        int getEmpCount()
        {
            return empCount;
        }
        //sorting algorithm methods
        void empSwap(int i, int iMin);
        void selectionSort();
        void insertionSort();
        void bubbleSort();

        // merge sort
        void mergeSort(Employee* e, int n);
        void mergeEmp(Employee* e, Employee l[], Employee r[], int nl, int nr);
        //helper function to call merge
        void callMerge();

        //quick sort
        int QPartition(int start, int last);
        void quickSort(int start, int last);
        //helper function to call quick sort
        void CallQuick();

        // print emps
        void printSortedEmps();
};

#endif // EMPLOYEESORT_H
