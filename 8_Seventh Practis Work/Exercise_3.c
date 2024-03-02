#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Get_Number();
int Get_Option();
void Create_Text_File(char file[], char option[]);
void Load_File_Text(char file[], char option[]);
void Read_Text_File(char file[], char option[]);
void Read_Salary_Report(char file[], char option[]);

int main(){
    /**/
    srand(time(NULL));

    /**/
    char file[] = "salary.txt";
    int option = -1;

    /**/
    while(option != 0){
        system("cls");
        printf("\t\t\t\t Menu \n\n");
        printf("\t\t 1. Create 'salary.txt' file!\n");
        printf("\t\t 2. Write to 'salary.txt' file (Automatically)!\n");
        printf("\t\t 3. Read the contents of the 'salary.txt' file!\n");
        printf("\t\t 4. Read salary report!\n");
        printf("\n\t\t  Enter '0' to exit the menu: "); 
        option = Get_Option();

        switch(option){
            case 0: 
                printf("\n\n\n\t\t\t Until next time!!\n");
                system("Pause");
                system("cls");
                break;
            
            case 1:
                Create_Text_File(file, "w");
                system("Pause");
                system("cls");
                break;
            
            
            case 2:
                Load_File_Text(file, "a");
                system("Pause");
                system("cls");
                break;
            
            
            case 3:
                Read_Text_File(file, "r");
                system("Pause");
                system("cls");
                break; 
            
            case 4:
                Read_Salary_Report(file, "r");
                system("Pause");
                system("cls");
                break;
        
        }
    }

    return 0;
}

int Get_Number(){
    /*I declare the variables*/
    int flag = 1, Number;

    /*validates that what is entered by keyboard is a number between 1 and 50*/
    while(flag == 1){
        
        if((scanf("%d", &Number) != 1)  || Number < 1 || Number > 50){
            fflush(stdin);
            printf("\nInvalid input. Please enter a valid number! (The number must be between 1 and 50)\n");
            printf("Enter a valid number: ");
        }
            
        else{flag = 0;};
    }
    
    printf("\n");
    system("cls");

    return Number;
}

int Get_Option(){
    /*I declare the variables*/
    int flag = 1, Number;

    /*validates that what is entered by keyboard is a number between 0 and 4*/
    while(flag == 1){
        
        if((scanf("%d", &Number) != 1)  && (Number < 0 || Number > 4)){
            fflush(stdin);
            printf("\nInvalid input. Please enter a valid number! (The number must be between 0 and 4)\n");
            printf("Enter a valid number: ");
        }
            
        else{flag = 0;};
    }
    
    printf("\n");
    system("cls");

    return Number;
}

void Create_Text_File(char file[], char option[]){
    /*create and open the file*/
    FILE *fp = fopen(file, option);
    
    /*close the file to avoid issues, also it's a good programming practice*/
    fclose(fp);
}

void Load_File_Text(char file[], char option[]){
    /*open the file to write/read*/
    FILE *fp = fopen(file, option);

    /*if the file couldn't be opened, print the opening error message*/
    if(fp == NULL){
        perror("Opening error!\n");
    }

    /**/
    printf("Cuantas sucursales hay en la empresa?: ");
    int branch = Get_Number();
    int i = 0, j, k, departament, employees;
    int departament_code = 0, employee_code = 0, branch_code = 0;
    float salary;

    /**/
    while(i < branch){
        branch_code += (rand() % 3) + 1;
        departament = (rand() % 10) + 1;
        j = 0;

        /**/
        while(j < departament){
            departament_code += (rand() % 2) + 1;
            employees = (rand() % 10) + 1;
            k = 0;

            /**/
            while(k < employees){
                employee_code += (rand() % 2) + 1;
                salary = (((rand() % 10000) + 120000) + (float)(rand() % 100) / 100);

                fprintf(fp, "%d-%d-%d-%.2f\n", branch_code, departament_code, employee_code, salary);
                
                k++;
            }
            employee_code = 0;
            j++;
        }
        departament_code = 0;
        i++;
    }

    /*close the file to prevent the written data from being lost, also it's a good programming practice*/
    fclose(fp);
}

void Read_Text_File(char file[], char option[]){
    /*open the file to read from it*/
    FILE *fp = fopen(file, option);

    /*if the file couldn't be opened, print the corresponding message to the screen*/
    if(fp == NULL){
        perror("Opening error!\n");
    }

    /*create the variables*/
    int branch_code, departament_code, employee_code;
    float salary;

    /*header for better organization*/
    printf("| BRANCH CODE | \t | DEPARTAMENT CODE | \t | EMPLOYEE CODE | \t | SALARY |\n");

    /**/
    rewind(fp);
    fscanf(fp, "%d-%d-%d-%f", &branch_code, &departament_code, &employee_code, &salary);
    while(feof(fp) == 0){
        printf("%8d \t\t\t %3d \t\t %9d \t\t$ %.2f\n", branch_code, departament_code, employee_code, salary);
        fscanf(fp, "%d-%d-%d-%f", &branch_code, &departament_code, &employee_code, &salary);
    }

    /*close the file so that no information is lost and there are no future issues, also it's a good programming practice*/
    fclose(fp);

    printf("Finished reading the file!...\n");
    system("Pause");
    system("cls");
}

void Read_Salary_Report(char file[], char option[]){
    /*Open the file to read from it*/
    FILE *fp = fopen(file, option);

    /*if the file couldn't be opened, print the corresponding message to the screen*/
    if(fp == NULL){
        perror("Opening error!\n");
    }

    /*create the variables*/
    int previous_branch_code, branch_code, previous_departament_code, departament_code, employee_code;
    float salary, departament_salary, branch_salary;

    /**/
    rewind(fp);
    
    /**/
    fscanf(fp, "%d-%d-%d-%f", &branch_code, &departament_code, &employee_code, &salary);
    while(feof(fp) == 0){
        printf("\t\t\tREPORTE DE SUELDO\n\n");
        previous_branch_code = branch_code;
        branch_salary = 0.0;

        /**/
        printf("BRANCH CODE NUMBER %d:\n", previous_branch_code);
        printf("| DEPARTAMENT CODE | \t | EMPLEOYEE CODE | \t | SALARY |\n");

        /**/
        while(feof(fp) == 0 && previous_branch_code == branch_code){
            previous_departament_code = departament_code;
            departament_salary = 0.0;

            /**/
            while(feof(fp) == 0 && previous_departament_code == departament_code){
                printf("%10d \t\t\t %d \t\t $ %.2f\n", previous_departament_code, employee_code, salary);
                departament_salary += salary;

                /**/  
                fscanf(fp, "%d-%d-%d-%f", &branch_code, &departament_code, &employee_code, &salary);
            }

            /**/
            printf("SALARY EXPENDITURE OFDEPARTAMENT %d : $ %.2f\n", previous_departament_code, departament_salary);
            system("Pause");

            branch_salary += departament_salary;
        }
        /**/
        printf("SALARY EXPENDITURE OF BRANCH: $ %.2f\n", branch_salary);
        system("Pause");
        system("cls");
    }

    /*close the file so that no information is lost and there are no future issues, also it's a good programming practice*/
    fclose(fp);
}