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
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    char file[] = "salary.txt";
    int option = -1;

    /*Loop that displays the menu until a '0' is entered in 'option'; then, call the functions to work with the files (create, 
    load, read, and extract statistics from it)*/
    while(option != 0){
        system("cls");
        printf("\t\t\t\t Menu \n\n");
        printf("\t\t 1. Create 'salary.txt' file!\n");
        printf("\t\t 2. Write to 'salary.txt' file (Automatically)!\n");
        printf("\t\t 3. Read the contents of the 'salary.txt' file!\n");
        printf("\t\t 4. Salary report for the branches!\n");
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

    /*ask the user for the number of branches the company has and create the variables I'll use in the function*/
    printf("How many branches does the company have?: ");
    int branch = Get_Number();
    int i = 0, j, employees, branch_code = 0, employee_code = 0; 
    float salary = 0.0;

    /*loop that generates the branch code and the number of employees it has*/
    while(i < branch){
        employees = (rand() % 10) + 1;
        branch_code += (rand() %2) + 1;
        j = 0;

        /*this loop is responsible for loading the branch data into the file, when there's no more data, exit the loop*/
        while(j < employees){
            employee_code += (rand() % 2) + 1;
            salary = (((rand() % 10000) + 120000) + (float)(rand() % 100) / 100);
            fprintf(fp, "%d - %d - %.2f\n", branch_code, employee_code, salary);
            j++;
        }
        employee_code = 0;
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
    int branch_code, employee_code;
    float salary;

    /*header for better organization*/
    printf("| BRANCH CODE | \t | EMPLOYEE CODE | \t | SALARY |\n");

    /* move the pointer to the beginning of the file; read the data and place it in the corresponding variables, print the read data to 
    the screen (repeat this process until reaching the end of the file or there's no more data to read)*/
    rewind(fp);
    fscanf(fp, "%d - %d - %f", &branch_code, &employee_code, &salary);
    while(feof(fp) == 0){
        printf("| %-12d | \t | %-13d | \t | $ %.2f |\n", branch_code, employee_code, salary);
        fscanf(fp, "%d - %d - %f", &branch_code, &employee_code, &salary);
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
    int branch = 1, branch_code, previous_branch_code, employee_code;
    float salary, branch_salary;

    /*read the data from the first row of the file*/
    rewind(fp);
    
    /*the loop reads the data from the file until reaching its end or there's no more data to read*/
    fscanf(fp, "%d - %d - %f", &branch_code, &employee_code, &salary);
    while(feof(fp) == 0){
        previous_branch_code = branch_code;
        branch_salary = 0.0;
        
        printf("BRANCH NUMBER %d:\n\n", branch);
        printf("BRANCH CODE: #%i\n", previous_branch_code);
        printf("| EMPLOYEE CODE | \t\t| SALARY |\n");

        /*in this loop, the data of branch x is printed until the branch code changes*/
        while(feof(fp) == 0 && previous_branch_code == branch_code){
            printf("| %-15d | \t\t| $ %-6.2f |\n", employee_code, salary);
            branch_salary += salary;
            fscanf(fp, "%d - %d - %f", &branch_code, &employee_code, &salary);
        }

        /*print the expenditure of branch x*/
        printf("SALARY EXPENDITURE OF BRANCH: $%.2f\n", branch_salary);
        branch++;
        
        system("Pause");
        system("cls");
    }

    /*close the file so that no information is lost and there are no future issues, also it's a good programming practice*/
    fclose(fp);
}
