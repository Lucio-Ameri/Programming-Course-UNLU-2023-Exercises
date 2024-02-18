#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_SURNAME_ID 100
#define NUMBER_OF_PERSONS 100 
#define NAME_SURNAME_ID_SIZE 100

int Get_Number();
void Get_Word(char *word);
void Get_ID(char *ID, int size_ID);
void Show_Array(char tensor[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], int persons);
void Load_Array(char tensor[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], int ID_size, int persons);
void Search_for_Person(char tensor[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], char ID_search[], int persons);

int main(){
    
    /*I declare the variables*/
    int persons, ID_size = 10, loop = 0;
    char Individual_Information[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], ID_search[ID_size];
    
    /*I ask the user for the number of people they are going to input into the list, and clear the '\n' from the buffer*/
    printf("Enter the number of people on the list: "); 
    persons = Get_Number();
    while (getchar() != '\n');

    /*I load the list and then display it on the screen*/
    Load_Array(Individual_Information, ID_size, persons);
    Show_Array(Individual_Information, persons);

    /*Loop that asks the user for a DNI to search for it in the list and if it's found, display it on the screen*/
    while(loop == 0){
        /*I enter the ID*/
        printf("Enter the ID number of the person you wish to search for in the list: "); 
        Get_ID(ID_search, ID_size);

        /*Searches the list for the entered ID. If it's found, display it; otherwise, show an error message*/
        Search_for_Person(Individual_Information, ID_search, persons);
        system("Pause");
        system("cls");

        /*I ask the user if there are any more IDS they want to search for in the list*/
        printf("Do you want to search for another ID number? (Enter 0 if you want to continue; enter 1 if there are no more ID numbers to search for): "); 
        loop = Get_Number();
        while (getchar() != '\n');
        system("cls");

        /*If the entered option is different from the valid ones, keep prompting until a valid option is entered*/
        while (loop != 0 && loop != 1) {
        printf("Please enter a valid value (0 or 1): "); 
        loop = Get_Number();
        while (getchar() != '\n');
        system("cls");
        
        }
    }
    
    system("cls");
    
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

    system("cls");

    return Number;
}

void Get_Word(char *word){
    /*I declare the variables*/
    int i, aux = 0;
    
    /*I ask the user for the name or the last name of the person they are going to enter into the list*/
    fgets(word, NAME_SURNAME_ID_SIZE, stdin);
    fflush(stdin);
    
    /*I replace the newline character with the empty character*/
    if(word[strlen(word) - 1] == '\n'){
        word[strlen(word) - 1] = '\0';
    }

    /*I check that what the user entered consists only of letters*/
    for(i = 0; word[i] != '\0'; i++){
        if(!isalpha(word[i])){
            aux = 1;
        }
        
        if(aux == 1){
            break;
        }
    }
    
    /*¡If what was entered is not only letters, I ask again until it is*/
    while(aux == 1){
        aux = 0;
        
        printf("\nInvalid Name/Surname! Please enter a name/surname without numbers or special characters!: ");
        
        fgets(word, NAME_SURNAME_ID_SIZE, stdin);
        fflush(stdin);

        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }

        for(i = 0; word[i] != '\0'; i++){
            if(!isalpha(word[i])){
                aux = 1;
            }
            
            if(aux == 1){
                break;
            }
        }

    }
    
    /*I change the entered content to all uppercase*/
    for(i = 0; word[i] != '\0'; i++){
        word[i] = toupper(word[i]);
    }

}

void Get_ID(char *ID, int size_ID){
    /*I declare the variables*/
    int i, aux = 0; 

    /*I enter the ID*/
    fgets(ID, size_ID, stdin);
    fflush(stdin);

    /*I replace the newline character with the empty character*/
    if(ID[size_ID - 1] == '\n'){
        ID[size_ID - 1] = '\0';
    }  

    /*If what was entered is not a number, I change the auxiliary variable to then ask for the ID again*/
    for(i = 0; ID[i] == '\0'; i++){
        if(ID[i] <'0' || ID[i] > '9'){
            aux = 1;
        }
        
        if(aux == 1){
            break;
        }
    }

    /*Ask for the ID again until a valid ID is entered*/
    while(aux == 1){
        aux = 0;
        
        printf("\nInvalid ID! Please enter a ID without letters or special characters!: ");
        
        fgets(ID, size_ID, stdin);
        fflush(stdin);

        if(ID[size_ID - 1] == '\n'){
            ID[size_ID - 1] = '\0';
        }  

        for(i = 0; ID[i] == '\0'; i++){
            if(!isdigit(ID[i])){
                aux = 1;
            }
        
            if(aux == 1){
                break;
            }
        }
    }

}

void Show_Array(char tensor[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], int persons) {
    /*List header.*/
    printf("NAMES\t\tSURNAMES\t\tIDS\n");
    
    /*Display on the screen the name, last name, and ID of person j*/
    for (int j = 0; j < persons; j++) {
        printf("%s\t\t%s\t\t\t%s\n", tensor[0][j], tensor[1][j], tensor[2][j]);
    }

    system("Pause");
    system("cls");
}

void Load_Array(char tensor[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], int ID_size, int persons){
    /*I declare the variables*/
    char name[NAME_SURNAME_ID], surname[NAME_SURNAME_ID], ID[ID_size];
    int i;

    /*I ask for the name, last name, and ID of the person, and then load it into their corresponding space, repeating 
    this process until all people are loaded.*/
    for(i = 0; i < persons; i++){
        printf("Enter the name of person n. %d: ", i + 1);
        Get_Word(name);

        printf("Enter the last name of person n %d: ", i + 1);
        Get_Word(surname);

        printf("Enter the DNI of person n %d: ", i + 1);
        Get_ID(ID, ID_size);

        /*Copy the data to the matrix.*/
        strcpy(tensor[0][i], name);
        strcpy(tensor[1][i], surname);
        strcpy(tensor[2][i], ID);

        system("cls");
    }
}

void Search_for_Person(char tensor[NAME_SURNAME_ID][NUMBER_OF_PERSONS][NAME_SURNAME_ID_SIZE], char ID_search[], int persons){
    /*I declare the variables*/
    int i, aux = 0, counter = 0;
    
    /*I search for the ID, if found, I display the name and last name of the person on the screen. If not found, 
    I inform on the screen.*/
    for(i = 0; i < persons; i++){
        if(strcmp(tensor[2][i], ID_search) == 0){
            aux = 1;
            break;
        }
        counter++;
    }

    if(aux == 1){
        printf("The person you're searching for was found. They are: %s %s\n", tensor[0][counter], tensor[1][counter]);
    }

    else{
        printf("The person you searched for was not found!!\n");
    }

}