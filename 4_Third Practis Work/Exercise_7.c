#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 100
#define COLUMNS 3

int Get_Number();
void Show_Array(int Array[ROWS][COLUMNS], int Persons);
void Load_array(int Array[ROWS][COLUMNS], int Persons);
int Sex_Generator();
int Marital_Status_Generator();
int Age_Generator();
void Statistics(int Array[ROWS][COLUMNS], int Persons, int sex, int martial_status, int age);


int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    int Array[ROWS][COLUMNS], Persons, sex, martial_status, age, option = 0;

    /*I ask the user to enter the number of people who will be on the list*/
    printf("How many people does the array contain?: ");
    Persons = Get_Number();

    /*I load and display the array on the screen*/
    printf("Situation of the participating individuals.:\n");
    Load_array(Array, Persons);
    Show_Array(Array, Persons);

    /*This loop will allow searching for the provided conditions as many times as desired.*/
    while(option == 0){
        
        printf("We will display the statistics according to the searched characteristics.!\n");
        
        /*I request the gender to search for. If the input is not valid, I will ask for it again until it is valid.*/
        printf("Enter a gender (enter '1' to search for 'MALE'; enter '2' to search for 'FEMALE'): ");
        sex = Get_Number();
        while(sex != 1 && sex != 2){
            printf("Invalid input! You must enter '1' or '2'!: ");
            sex = Get_Number();
        }
        
        /*I request the marital status to search for. If the input is not valid, I will ask for it again until it is valid.*/
        printf("Enter a marital status (enter '1' to search for 'SINGLE'; enter '2' to search for 'MARRIED'; enter '3' to search for 'WIDOWED'): ");
        martial_status = Get_Number();
        while(martial_status != 1 && martial_status != 2 && martial_status != 3){
            printf("Invalid input! You must enter '1' or '2' or '3'!: ");
            martial_status = Get_Number();
        }

        /*I request the age to search for. If the input is not valid, I will ask for it again until it is valid.*/
        printf("Enter an age (between '1' and '70'): ");
        age = Get_Number();
        while(age < 1 && age > 70){
            printf("Invalid input! You must enter an age between '1' and '70': ");
            age = Get_Number();
        }

        /*I search for the number of matches and display it on the screen.*/
        Statistics(Array, Persons, sex, martial_status, age);

        /*I ask the user if they want to continue searching for other conditions.*/
        printf("Do you want to search for more statistics? (Enter '1' if you don't want to search anymore; enter '0' if you want to continue searching): ");
        option = Get_Number();
        while(option != 0 && option != 1){
            printf("Invalid input! You must enter '1' or '0': ");
            option = Get_Number();
        }
    }

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

int Sex_Generator(){
    /*I declare the variables*/
    int n;

    /*I generate a random number between 1 and 2, and return it.*/
    n = (rand() % 2) + 1;

    return n;
}

int Marital_Status_Generator(){
    /*I declare the variables*/
    int n;

    /*I generate a random number between 1 and 3, and return it.*/
    n = (rand() % 3) + 1;

    return n;
}

int Age_Generator(){
    /*I declare the variables*/
    int n;

    /*I generate a random number between 1 and 70, and return it.*/
    n = (rand() % 70) + 1;

    return n;
}

void Show_Array(int Array[ROWS][COLUMNS], int Persons) {
    /*I declare the variables*/
    int i, j;

    printf("Sex\tMarital Status\tAge\n");
    /*print the array*/
    for (i = 0; i < Persons; i++) {
        for (j = 0; j < 3; j++) {
            
            if (j == 0) {
                printf("%d\t\t", Array[i][j]);
            } 
            
            else if (j == 1) {
                printf("%d\t", Array[i][j]);
            } 
            
            else {
                printf("%d\n", Array[i][j]);
            }
        }
    }

    system("Pause");
    system("cls");
}

void Load_array(int Array[ROWS][COLUMNS], int Persons){
    /*I declare the variables*/
    int i = 0;

    /*I load the array with its corresponding values.*/
    while(i < Persons){
        Array[i][0] = Sex_Generator();
        Array[i][1] = Marital_Status_Generator();
        Array[i][2] = Age_Generator();

        i++;
    }
}

void Statistics(int Array[ROWS][COLUMNS], int Persons, int sex, int martial_status, int age){
    /*I declare the variables*/
    int i, counter = 0;

    /*I search for the matches, if found, the counter increases by 1.*/
    for(i = 0; i < Persons; i++){

        if(Array[i][0] == sex && Array[i][1]  == martial_status && Array[i][2] == age){
            counter++;
        }
    }

    /*I print what was searched for and what was found.*/
    printf("Of the %d people in the list, %d have the searched characteristics.: ", Persons, counter);

    if(sex == 1){
        printf("MALE, ");
    }
    else{
        printf("FEMALE, ");
    }

    if(martial_status == 1){
        printf("SINGLE, ");
    }
    else if(martial_status == 2){
        printf("MARRIED, ");
    }
    else{
        printf("WIDOWED, ");
    }

    printf("%d years!\n", age);

    system("Pause");
    system("cls");
}
