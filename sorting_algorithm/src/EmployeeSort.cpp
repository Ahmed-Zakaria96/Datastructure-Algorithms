#include "EmployeeSort.h"
#include "Employee.h"
#include <iostream>
#include "colors.h"

using namespace std;
//default constructor

EmployeeSort::EmployeeSort()
{
    ConsoleColor C;
    C.Blue();
    //ask user for array length and store value in empCount
    cout<<"Enter number of Employees: ";
    cin>> empCount;
    // allocate new array of size empCount
    emps = new Employee [empCount];
    if (emps)
    {
        for (int i = 0; i < empCount; i++)
        {
            C.LPurple();
            cout << "Employee "<< i+1 <<endl;
            C.White();
            emps[i].setEmpID();
            emps[i].setEmpSalary();
            cout<<endl;
        }
    } else {
        C.Red();
        cout << "Couldn't allocate memory!"<<endl;
        cout << "Exiting..."<<endl;
        return;
    }

}
//destructor
EmployeeSort::~EmployeeSort()
{
    //dtor
    delete[] emps;
}
//swap function
void EmployeeSort::empSwap(int i, int iMin)
{
    //swap function take indexes of 2 elements from array emps to swap them
    //order doesn't matter cause it is just 2 element
    Employee temp = emps[iMin];
    emps[iMin] = emps[i];
    emps[i] = temp;
}

//sorting

void EmployeeSort::selectionSort()
{
    /*each outer loop iteration will sort the smallest element of the unsorted array
    in its right position in the sorted array so outer loop is array length - 1 cause last element
    will be the left element after picking all small elements so it is sorted
    */
    for (int i = 0; i < empCount - 1; i++)
    {
        // mark the first element index as index of smallest at loop start
        int iMin = i;
        //loop through array to compare elements for the smallest value
        for (int j = i+1; j < empCount; j++ )
        {
            //compare based on id
            if (emps[j].getEmpID() < emps[iMin].getEmpID())
            {
                // if there is smaller element change iMin to this element index
                iMin = j;
            }
        }
        // swap element at index 1 our current position in loop and iMin smallest element index
        empSwap(i, iMin);
    }
}

void EmployeeSort::insertionSort()
{
    // start from 2nd element of the array to compare back ward
    for (int i = 1; i < empCount; i++)
    {
        //store value of i element in temp var
        Employee value = emps[i];
        //mark i element as empty index
        int emptyIndex = i;
        // emptyIndex > 0 to check there is something before to compare
        // emps[emptyIndex-1].getEmpID() > value.getEmpID()) to compare ids for smallest

        while (emptyIndex > 0 && emps[emptyIndex-1].getEmpID() > value.getEmpID())
        {
            // if element at index i > element at index i-1
            // set element at i to be element at i-1
            // then move empty index back ward
            // like pulling bigger elements to right to put smaller elements at left
            emps[emptyIndex] = emps[emptyIndex -1];
            emptyIndex -= 1;
        }
        // after completing pulling element put the stored element at loop start at the empty index
        emps[emptyIndex] = value;
    }
}

void EmployeeSort::bubbleSort()
{
    // loop through array compare each adjacent elements
    for (int i = 0; i < empCount-1; i++)
    {
        //counter to track if any swaps happened
        //resets to 0 after each loop iteration
        int swaps = 0;
        //loop through array - i -1 because for each iteration the array size is smaller by 1
        // -1 to be able to compare last 2 elements [j] and [j+1] not to exceed boundary
        for (int j = 0; j < empCount-i-1; j++)
        {
            //compare based on id
            if (emps[j].getEmpID() > emps[j+1].getEmpID())
            {
                // send element indexes to be swapped to swap function
                empSwap(j, j+1);
                // increase swap counter by 1
                swaps +=1;
            }
        }
        // if no swapps happened in current iteration then array is sorted
        if (!swaps)
        {
            break;
        }
    }
}

int EmployeeSort::QPartition(int start, int last)
{
    // choose a pivot last element for example
    int pivot = last;
    // index will start with 0 then updated based on partition
    int pIndex = start;

    // loop through partition to see if there is elements smalled than pivot
    // if so place it in Pindex and increment pindex
    for (int i = start; i < last; i ++)
    {
        if (emps[i].getEmpID() < emps[pivot].getEmpID())
        {
            empSwap(i, pIndex);
            pIndex +=1;
        }
    }
    // after finishing partition loop swap pivot to be place in the right position pIndex
    empSwap(pIndex, last);
    return pIndex;
}

void EmployeeSort::quickSort(int start, int last)
{

    if (start < last)
    {
        int partionIndex;
        partionIndex = QPartition(start, last);
        quickSort(start, partionIndex-1);
        quickSort(partionIndex+1, last);
    }
}
void EmployeeSort::CallQuick()
{
    // helper function to pass object data to quick sort
    int last = empCount -1;
    int start = 0;
    quickSort(start, last);
}

void EmployeeSort::mergeEmp(Employee* e, Employee* l, Employee* r, int nl, int nr)
{
    // index for left array
    int i = 0;
    // index for right array
    int j = 0;
    // index for array will be merged in
    int k = 0;

    // compare current i and j with left and right array length
    // if one array is done no comparison will happen so we should exit loop

    while (i < nl && j < nr)
    {
        // compare first element in left with first element in right
        // put the smaller in e array
        if (l[i].getEmpID()<= r[j].getEmpID())
        {
            e[k] = l[i];
            // increase left array index
            i++;
        }else
        {
            e[k] = r[j];
            // increase right array index
            j++;
        }
        // after inserting in e[k] increase index
        k++;
    }
    // left over elements from left
    while (i < nl)
    {
        e[k]=l[i];
        // keep index updated not to overwrite
        i++;
        k++;
    }

    //left over elements from right
    while (j < nr)
    {
        e[k] = r[j];
        // keep index updated not to overwrite
        j++;
        k++;
    }
}

void EmployeeSort::mergeSort(Employee* e, int n)
{
    if (n < 2 )
    {
        return;
    }
    // split array into 2 halves
    int mid = n/2;
    // n-mid cause if n is odd number
    int rr= n-mid;

    // dynamically allocate arrays for splitting array
    Employee* left = new Employee [mid];
    Employee* right = new Employee [rr];

    // copy elements from array e from 0 to mid in array left
    for (int i = 0; i < mid; i++)
    {
        left[i] = e[i];
    }
    // copy elements from array e from mid to last element n-1 in array right
    for (int j = mid; j < n; j++)
    {
        right[j-mid] = e[j];
    }
    //recursive calls to keep splitting untill n = 1
    // call mergesort on left and pass its length
    mergeSort(left, mid);
    // call mergesort on right and pass its length
    mergeSort(right, rr);
    // after splitting is over merge splited arrays in their original array
    mergeEmp(e, left, right, mid, rr);

    // free dynamically allocated memory after merge is done
    delete(left);
    delete(right);
}

void EmployeeSort::callMerge()
{
    // helper function to call merge with data of the object
    mergeSort(emps, empCount);
}

void EmployeeSort::printSortedEmps()
{
    ConsoleColor C;
    C.LWhite();
    cout << "\nSorted array\n"<< endl;
    for (int i = 0; i < empCount ; i++)
    {
        C.Purple();
        cout<<"Employee "<< i+1<< endl;
        C.Green();
        cout<<"ID: "<<emps[i].getEmpID()<<endl;
        cout<<"Salary: "<<emps[i].getEmpSalary()<<endl;
        cout<<endl;
    }
}












