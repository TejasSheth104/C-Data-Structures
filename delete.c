/*C program to read and print employee's record using structure*/
 
#include <stdio.h>
 
/*structure declaration*/
struct employee{
    char name[30];
    int empId;
    float salary, da, hra, gross; 
};
 
int main()
{
    /*declare structure variable*/
    struct employee emp;
     
    /*read employee details*/
    printf("\nEnter details :\n");
    printf("Name ?:");          
	gets(emp.name);
    printf("ID ?:");            
	scanf("%d",&emp.empId);
    printf("Salary ?:");        
	scanf("%f",&emp.salary);
     
    if(emp.salary <= 10000){
        emp.da = emp.salary * 0.8;
        emp.hra = emp.salary * 0.2;
    }
    else if(emp.salary <= 20000){
        emp.da = emp.salary * 0.9;
        emp.hra = emp.salary * 0.25;
    }
    else{
        emp.da = emp.salary * 0.95;
        emp.hra = emp.salary * 0.3;
    }
    /* Calculate gross salary */
    emp.gross = emp.salary + emp.hra + emp.da;
    
    /*print employee details*/
    printf("\n\n\nEntered detail is:");
    printf("\nName: %s"   ,emp.name);
    printf("\nId: %d"     ,emp.empId);
    printf("\nGross Salary: %f\n",emp.gross);
    return 0;
}


