#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define WORKERS 1000
#define SIZE_NAME_SURNAME 50
#define CONDITION 50

typedef struct{
    char name[SIZE_NAME_SURNAME];
    char surname[SIZE_NAME_SURNAME];
    int age;
    char gender[CONDITION];
    char marital_status[CONDITION];
    float salary;
}record;

int Get_Number();
void Get_Word(char *word);
float Get_Salary();
void Status(char *word, int option);
void Sex(char *word, int option);
void Show_Array(record Array[], int workers);
void Load_Array(record *Array, int workers);
void Exercise_Request(record Array[], int workers);



int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    record employee[WORKERS];
    int number_of_employees;

    /*I ask the user to enter the number of employees they have*/
    printf("How many employees do you have?: ");
    number_of_employees = Get_Number();
    while (getchar() != '\n');

    /*I load and display on the screen the list of employees with all their information*/
    Load_Array(employee, number_of_employees);
    printf("EMPLOYEE LIST:\n");
    Show_Array(employee, number_of_employees);

    /*I calculate the requested statistics in the exercise*/
    Exercise_Request(employee, number_of_employees);

    return 0;
}

int Get_Number(){
    /*I declare the variables*/
    int flag = 0, Number;

    /*validates that what is entered by keyboard is a number*/
    if(scanf("%d", &Number) != 1 ){
        fflush(stdin);
        flag = 1;
        printf("\nInvalid input. Please enter a valid number!\n");
        
        while(flag == 1){
            printf("Enter a valid number: ");
            
            if(scanf("%d", &Number) != 1){
                fflush(stdin);
                printf("\nInvalid input. Please enter a valid number!\n");
            }
            
            else{flag = 0;}
        }
    }
    printf("\n");
    system("cls");

    return Number;
}

void Get_Word(char *word){
    /*I declare the variables*/
    int i, aux = 1;
    
    /*I ask the user for the name or the last name of the person they are going to enter into the list*/
    while(aux == 1){
        aux = 0;
        fgets(word, SIZE_NAME_SURNAME, stdin);
        fflush(stdin);
        
        /*I replace the newline character with the empty character*/
        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }

        /*I check that what the user entered consists only of letters*/
        for(i = 0; word[i] != '\0'; i++){
            if(!isalpha(word[i])){
                printf("\nInvalid Name/Surname! Please enter a name/surname without numbers or special characters!: ");
                aux = 1;
                break;
            }
            
            
        }
    }

    /*I convert the entered word to uppercase*/
    i = 0;
    while (word[i] != '\0') {
        word[i] = toupper(word[i]);
        i++;
    }

    printf("\n");
    system("cls");
    
}

float Get_Salary(){
    /*I declare the variables*/
    int flag = 0;
    float Number;

    do {
        /*validates that what is entered by keyboard is a number between $100.000 and $200.000*/
        printf("Enter a valid number: ");
        if(scanf("%f", &Number) != 1 ){
            fflush(stdin);
            flag = 1;
            printf("\nInvalid input. Please enter a valid number!\n");
        } 
        
        else if (Number < 100000 || Number > 200000) {
            printf("Number should be between 100,000 and 200,000\n");
            flag = 1;
        } 
        
        else {
            flag = 0;
        
        }
    } 
    
    while(flag == 1);

    printf("\n");
    system("cls");
    return Number;
}

void Sex(char *word, int option){
    /*Depending on what was entered in 'option', I save the corresponding gender of the employee in the variable 'word'*/
    if(option == 1){
        strcpy(word, "FEMALE");
        
        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }

    }
    
    else{
        strcpy(word, "MALE");
        
        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }
    }
}

void Status(char *word, int option){
    /*Depending on what was entered in 'option', the corresponding marital status of the employee will be placed 
    in the variable 'word'*/
    if(option == 1){
        strcpy(word, "SINGLE");

        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }
        
    }
    
    else if(option == 2){
        strcpy(word, "MARRIED");

        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }
    }

    else if(option == 3){
        strcpy(word, "DIVORCED");

        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }
    }

    else{
        strcpy(word, "OTHER");

        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }
    }
}

void Show_Array(record Array[], int workers){
    /*I declare the variables*/
    int i;

    /*I print the header, and with each iteration, I display all the information of employee[i]*/
    printf("%-15s | %-15s | %-10s | %-10s | %-15s | %-10s\n", "NAME", "SURNAME", "AGE", "GENDER", "MARITAL STATUS", "SALARY");
    for(i = 0; i < workers; i++){
        printf("%-15s | %-15s | %-10d | %-10s | %-15s | %-10.2f\n", Array[i].name, Array[i].surname, Array[i].age, Array[i].gender, Array[i].marital_status, Array[i].salary);
    }
    system("Pause");
    system("cls");
}

void Load_Array(record *Array, int workers){
    /*I declare the variables*/
    char name[SIZE_NAME_SURNAME], surname[SIZE_NAME_SURNAME], gender[CONDITION], marital_status[CONDITION];
    int i, option;

    /*In each iteration, I load the information of employee[i]*/
    for(i = 0; i < workers; i++){
        /*I ask the user for the employee's name*/
        printf("Please enter the name of employee %d: ", i + 1);
        Get_Word(name);
        strcpy(Array[i].name, name);

        /*I ask the user for the employee's last name*/
        printf("Please enter the last name of employee %d: ", i + 1);
        Get_Word(surname);
        strcpy(Array[i].surname, surname);

        /*I ask the user for the employee's age*/
        printf("cual es la edad del empleado %d?: ", i + 1);
        Array[i].age = Get_Number();
        while (getchar() != '\n');

        /*I ask the user to enter the employee's gender. If the entered option is not valid, I prompt the user to enter 
        the gender again until a valid option is provided*/
        printf("What is the gender of employee %d? (Enter '1' for female, '2' for male): ", i + 1);
        option = Get_Number();
        while (getchar() != '\n');
        
        while(option != 1 && option != 2){
            printf("Invalid input! Please enter '1' for female or '2' for male: ");
            option = Get_Number();
            while (getchar() != '\n');
        }

        Sex(gender, option);
        strcpy(Array[i].gender, gender);

        /*I ask the user to enter the marital status of the employee. If the entered option is not valid, I prompt the 
        user to enter the marital status again until a valid option is provided*/
        printf("What is the marital status of employee %d? (Enter '1' for single; '2' for married; '3' for divorced; '4' for other): ", i + 1);
        option = Get_Number();
        while (getchar() != '\n');

        while(option < 1 || option > 4){
            printf("Invalid input! Please enter '1' for single, '2' for married, '3' for divorced, '4' for other: ");
            option = Get_Number();
            while (getchar() != '\n');
        }

        Status(marital_status, option);
        strcpy(Array[i].marital_status, marital_status);

        /*I ask the user to enter a salary*/
        printf("Please enter the salary of employee %d (knowing that it ranges between $100,000 and $200,000): ", i + 1);
        Array[i].salary = Get_Salary();
        while (getchar() != '\n');
    }

}

void Exercise_Request(record Array[], int workers){
    /*I declare the variables*/
    int i, male_workers = 0, female_married_workers = 0, age_worker = 1000;
    char name[SIZE_NAME_SURNAME], surname[SIZE_NAME_SURNAME];
    float total_salary = 0.0;

    /*I calculate the requested statistics in the exercise and then display them on the screen*/
    for(i = 0; i < workers; i++){
        
        if(strcmp(Array[i].gender, "MALE") == 0){
            male_workers++;
        }

        if(strcmp(Array[i].gender, "FEMALE") == 0){
            if(strcmp(Array[i].marital_status, "MARRIED") == 0){
                female_married_workers++;
            }
        }

        if(Array[i].age < age_worker){
            strcpy(name, Array[i].name);
            strcpy(surname, Array[i].surname);
            age_worker = Array[i].age;
        }

        total_salary += Array[i].salary;
    }

    printf("RESULT:\n");
    printf("Number of male workers: %d\n", male_workers);
    printf("Number of female workers who are married: %d\n", female_married_workers);
    printf("The youngest employee is: %s %s with %d years old!\n", name, surname, age_worker);
    printf("Total sum of salaries: %10.2f\n", total_salary);

}