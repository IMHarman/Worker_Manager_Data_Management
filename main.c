#include <stdio.h>
#include <stdlib.h>

//Function to input manager records
void m_input()
{
    FILE *fptr;
    int m_eno;
    char m_name[20];
    float m_bpay, m_allow, m_ded;

    fptr = fopen("manager.txt", "a");
    printf("\n Enter the Manager details as asked.");
    printf("\n Employee Number: ");
    scanf("%d",&m_eno);
    printf("\n Employee Name: ");
    scanf("%s",&m_name);
    printf("\n Employee Basic Pay: ");
    scanf("%f",&m_bpay);
    printf("\n Employee Allowances: ");
    scanf("%f",&m_allow);
    printf("\n Employee deduction: ");
    scanf("%f",&m_ded);
    fprintf(fptr, "%d %s %f %f %f \n",m_eno,m_name,m_bpay,m_allow,m_ded);

    fclose(fptr);
}

//Function to input worker records
void w_input()
{
    FILE *fptr;
    int w_eno;
    char w_name[20];
    float w_bpay, w_allow, w_ded;

    fptr = fopen("workers.txt", "a");
    printf("\n Enter the Worker details as asked.");
    printf("\n Employee Number: ");
    scanf("%d",&w_eno);
    printf("\n Employee Name: ");
    scanf("%s",&w_name);
    printf("\n Employee Basic Pay: ");
    scanf("%f",&w_bpay);
    printf("\n Employee Allowances: ");
    scanf("%f",&w_allow);
    printf("\n Employee deduction: ");
    scanf("%f",&w_ded);
    fprintf(fptr, "%d %s %f %f %f \n",w_eno,w_name,w_bpay,w_allow,w_ded);

    fclose(fptr);
}

//Function to print manager records
void m_print()
{
    FILE *fptr;
    int m_eno,c;
    char m_name[20];
    float m_bpay, m_allow, m_ded;
    fptr = fopen("manager.txt", "r");
    if ((fptr = fopen("manager.txt","r")) == NULL)
    {
       printf("Error! opening file");
        exit(1);
    }
    c = fgetc(fptr);
    printf("\n ---------------EMPLOYEE DETAILS---------------");
    printf("\nE.NO. \t Name \t BPay \t\t Allowance \t Deduction \n\n");
    while(c != EOF)
    {
        fscanf(fptr,"%d%s%f%f%f\n",&m_eno,&m_name,&m_bpay,&m_allow,&m_ded);
        printf("%d \t %s \t %f \t %f \t %f \n",m_eno,m_name,m_bpay,m_allow,m_ded);
        getch();
    }
    fclose(fptr);
    getch();
}

//Function to print worker records
void w_print()
{
    FILE *fptr;
    int w_eno,c;
    char w_name[20];
    float w_bpay, w_allow, w_ded;
    fptr = fopen("workers.txt", "r");
    if ((fptr = fopen("workers.txt","r")) == NULL)
    {
       printf("Error! opening file");
        exit(1);
    }
    c = fgetc(fptr);
    printf("\n ---------------EMPLOYEE DETAILS---------------");
    printf("\nE.NO. \t Name \t BPay \t\t Allowance \t Deduction \n\n");
    while(c != EOF)
    {
        fscanf(fptr,"%d%s%f%f%f\n",&w_eno,&w_name,&w_bpay,&w_allow,&w_ded);
        printf("%d \t %s \t %f \t %f \t %f \n",w_eno,w_name,w_bpay,w_allow,w_ded);
        getch();
    }
    fclose(fptr);
    getch();
}

int main()
{
    int ch,ans;
    do
    {
        printf("---------------------MENU---------------------");
        printf("\n To enter a record of: ");
        printf("\n 1. Manager");
        printf("\n 2. Worker");
        printf("\n Choose between 1 and 2. Else press any key to exit. \n Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : m_input(); break;
            case 2 : w_input(); break;
            default: printf("\n Enter a valid input.");
        }
        printf("\n To enter another record press 1 or to exit press 0.");
        printf("\n Enter your choice : ");
        scanf("%d",&ans);
    }while(ans == 1);
    {
        printf("---------------------MENU---------------------");
        printf("\n To print the record of: ");
        printf("\n 1. Manager");
        printf("\n 2. Worker");
        printf("\n Choose between 1 and 2. Else press any key to exit. \n Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : m_print(); break;
            case 2 : w_print(); break;
            default: printf("\n Enter a valid input."); return 0;
        }
        printf("\n To continue press 1 else press 0 to exit.");
        printf("\n Enter your choice : ");
        scanf("%c",&ans);
    }while(ans == 1);
    return 0;
}
