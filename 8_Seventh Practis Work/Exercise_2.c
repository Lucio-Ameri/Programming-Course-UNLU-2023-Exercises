#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Get_Number();
int Get_Option();
void Create_Text_File(char file[], char option[]);
void Load_File_Text(char file[], char option[]);
void Read_Text_File(char file[], char option[]);
void Bank_Transactions(char file[], char option[]);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    char file[] = "transactions.txt";
    int option = -1;

    /*Loop that displays the menu until a '0' is entered in 'option'; then, call the functions to work with the files (create, 
    load, read, and extract statistics from it)*/
    while(option != 0){
        system("cls");
        printf("\t\t\t\t Menu \n\n");
        printf("\t\t 1. Create 'transactions.txt' file!\n");
        printf("\t\t 2. Write to 'transactions.txt' file (Automatically)!\n");
        printf("\t\t 3. Read the contents of the 'transactions.txt' file!\n");
        printf("\t\t 4. Transaction report!\n");
        printf("\n\t\t  Enter '0' to exit the menu: "); 
        option = Get_Option();
        
        switch(option){
            case 0: 
                printf("\n\n\n\t\t\t Until next time!\n");
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
                Bank_Transactions(file, "r");
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

    /*validates that what is entered by keyboard is a number between 1 and 1000*/
    while(flag == 1){
        
        if((scanf("%d", &Number) != 1)  || Number < 1 || Number > 1000){
            fflush(stdin);
            printf("\nInvalid input. Please enter a valid number! (The number must be between 1 and 1000)\n");
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

    /*Ask the user to enter the number of customers the bank has; create the variables that will be used in the function*/
    printf("How many customers does the bank have?: ");
    int bank_accounts = Get_Number();
    int i = 0, j = 0, account_number = 0, number_of_transactions = 0, movement;
    float amount = 0.0;

    /*This loop is responsible for loading the account code and the number of transactions for customer x*/
    while(i < bank_accounts){
        account_number += (rand() % 3) + 1;
        number_of_transactions = (rand() % 10) + 1;
        j = 0;

        /*This loop is responsible for loading the customer's data into the file, when there are no more transactions to load, it 
        moves on to the next customer*/
        while(j < number_of_transactions){
            movement = (rand() % 2) + 1;
            amount = (rand() % 30000) + ((float)(rand() % 100) /100);
            fprintf(fp, "%d - %d - %.2f\n", account_number, movement, amount);

            j++;
        }

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
        perror("Error de apertura!\n");
    }

    /*create the variables*/
    int account_number, movement;
    float amount;

    /* print the header to improve the file comprehension; read the first line of the file and load it into the corresponding 
    variables; the loop reads and prints the data until there are no more data to read in the file or it reaches the end of the file*/
    printf("| ACCOUNT NUMBER | \t | TRANSACTION | \t | AMOUNT |\n");
    fscanf(fp, "%d - %d - %f", &account_number, &movement, &amount);
    while(feof(fp) == 0){
        printf("%d %d %.2f ", account_number, movement, amount);
        fscanf(fp, "%d - %d - %f", &account_number, &movement, &amount);
    } 
}

void Bank_Transactions(char file[], char option[]){
    /*Open the file to read from it*/
    FILE *fp = fopen(file, option);

    /*if the file couldn't be opened, print the corresponding message to the screen*/
    if(fp == NULL){
        perror("Opening error!\n");
    }

    /*create the variables*/
    int account_number, previous_account_number, movement;
    float amount = 0.0, current_balance;

    /*read the data from the first row; this loop is responsible for reading, printing, and initializing the variables of customer 
    x until there are no more data to read or it reaches the end of the file*/
    fscanf(fp, "%d - %d - %f", &account_number, &movement, &amount);
    while(feof(fp) == 0){
        previous_account_number = account_number;
        current_balance = 0.0;

        printf("\tCURRENT ACCOUNT TRANSACTIONS REPORT:\n");
        printf("CUSTOMER: %i\n\n", previous_account_number);
        
        /*this loop loads the total balance of customer x until the account number changes or until there are no more data to read 
        or it reaches the end of the file*/
        while(feof(fp) == 0 && previous_account_number == account_number){
            printf("%d - %d - %.2f\n", account_number, movement, amount);

            if(movement == 1){
                current_balance += amount;
            }
            
            else{
                current_balance -= amount;
            }

            fscanf(fp, "%d - %d - %f", &account_number, &movement, &amount);
        }

        /*print the net balance of customer x*/
        printf("\nNET BALANCE: $%.2f\n", current_balance);
        system("Pause");
        system("cls");
    }

    /*close the file so that no information is lost and there are no future issues, also it's a good programming practice*/
    fclose(fp);
}