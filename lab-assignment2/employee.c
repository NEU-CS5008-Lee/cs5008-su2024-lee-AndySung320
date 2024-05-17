// name: Di-En Sung
// email: sung.di@northeastern.edu.tw

/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    // Add your code here
    for (int i = 0; i < n; i++){
        printf("Enter the employeeID, Name, designation and Department of Employee %d:\n", i+1);
        scanf("%d", &(s+i)->empId);
        scanf("%s", (s+i)->Name);
        scanf("%s", (s+i)->Designation);
        scanf("%s", (s+i)->Dept);
        printf("\n");
    }
}
/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    // Add your code here
    for (int i = 0; i < n; i++){
        printf("The details of the Employee %d:\n", i+1);
        printf("empID: %d\n", &(s+i)->empId);
        printf("Name: %s\n", (s+i)->Name);
        printf("Designation: %s\n", (s+i)->Designation);
        printf("Dept: %s\n", (s+i)->Dept);
        printf("\n");
    }
    
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    // Add your code here
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    employee_t* test_emp = (employee_t*)malloc(n * sizeof(employee_t));
    if (test_emp == NULL){
        printf("Memory allocation failed.\n");
        return -1;
    }

    readData(n, test_emp);
    display(n, test_emp);

    free(test_emp);
    return 0;

}

