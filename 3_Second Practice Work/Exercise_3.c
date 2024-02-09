#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#define SIZE 100

int Get_Number();
char Get_Char();
void Show_Array(int array[], int size);
void Load_Array(int *array, int *size_array, int option);
void Order_the_Array(int *array, int size);
void Request_Function(int *array, int *size_array, char action, int number);
void Delete_Element(int *array, int *size_array, int number_to_delete);
void Add_Last_Position(int *array, int *size_array, int number);
void Add_Where_Requested(int *array, int *size_array, int number);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    /*I declare the variables*/
    int array[SIZE], option = 0, size_array, number, flag = 1;
    char action;

    /*I call the function to input a validated number*/
    printf("Enter the size of the array!(greater than 0) : ");
    size_array = Get_Number();

    printf("How would you like to load the array? (1 = manually; 2 = empty; 3 = random) : ");
    option = Get_Number();

    /*I load the arrays, I sort the array and then I display it on the screen*/
    Load_Array(array, &size_array, option);
    Order_the_Array(array, size_array);
    Show_Array(array, size_array);
    system("pause");
    system("cls");

    /*In this loop, it operates as an interactive menu, allowing the user to input the desired option. If a certain 
    option is entered, the 'flag' changes, and the loop terminates*/
    while(flag == 1){
        
        printf("What action would you like to perform on the array?\n");
        printf("\t\t press 'I' to add a number in the last position of the array.\n");
        printf("\t\t press 'B' to remove a number of the array.\n");
        printf("\t\t press 'A' to add a number to the desired position of the array.\n");
        printf("\t\t press 'Q' to Exit.\n");
        printf("Enter The action!: "); action = Get_Char();
        system("cls");

        /*I request the respective number with which the actions will be performed*/
        printf("Enter a number: "); number = Get_Number();
        
        if(action != 'Q'){
        Request_Function(array, &size_array, action, number);
        }

        else{
            flag = 0;
        }
        
        /*I display the array every time an action is performed*/
        Show_Array(array, size_array);
        system("pause");
        system("cls");
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

    return Number;
}

char Get_Char(){
    /*I declare the variables*/
    int flag = 0; 
    char word;

    /*validates that what is entered by keyboard is a letter*/
    if(scanf(" %c", &word) != 1 || !isalpha(word)){
        fflush(stdin);
        flag = 1;
        printf("\nInvalid input. Please enter a valid letter!\n");
        
        while(flag == 1){
            printf("Enter a valid letter: ");
            
            if(scanf(" %c", &word) != 1){
                fflush(stdin);
                printf("\nInvalid input. Please enter a valid letter!\n");
            }
            
            else{flag = 0;}
        }
    }

    while (getchar() != '\n');

    printf("\n");

    return toupper(word);
}

void Show_Array(int array[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/ 
    printf("The array is: \n\n");
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }
    printf("\n\n");
}

void Load_Array(int *array, int *size_array, int option){
    /*I declare the variables*/
    int i, max, min;

    /*I use a switch statement to load the array according to the option entered previously*/
    switch (option){
        case 1:
            /*The numbers are manually entered into the array*/
            printf("You should enter %d numbers (one at a time)!\n", *size_array);
            
            for(i = 0; i < *size_array; i++){
                printf("Please enter the number %d : ", i + 1);
                array[i] = Get_Number();
            }

            system("Pause");
            system("cls");
            break;
        
        case 2:
            /*the array is initialized with zeros to mimic being empty*/
            for(i = 0; i < *size_array; i++){
                array[i] = 0;
            }
            *size_array = 0;
            break;

        case 3:
            /*the array is populated with numbers ranging between the provided minimum and maximum*/
            printf("You will have to specify to me between which number and which number you want the content of the array to be loaded!\n");
            printf("Enter from which number you want to load the array: "); min = Get_Number();
            printf("Enter up to which number you want to load the array: "); max = Get_Number();

            for(i = 0; i < *size_array; i++){
                array[i] = min + rand() % (max - min + 1);
            }
            system("cls");
            break;
    }

}

void Order_the_Array(int *array, int size){
    /*I declare the variables*/
    int i, j, aux;

    /*I use nested loops to traverse the array, looking for values that are greater than the next one in order 
    to sort the array from smallest to largest*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            
            if((array[i] > array[j]) || (array[i] == 0)){
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void Request_Function(int *array, int *size_array, char action, int number){

    switch(action){
        case 'I':
            /*Add a provided element to the last position of the array if possible*/
            if(*size_array < SIZE){
                Add_Last_Position(array, size_array, number);
            }
            
            else{
                printf("Sorry! It's not possible to add another element to the array; it's full. Remove an element to add a new number!.\n");
            }
            break;

        case 'B':
            /*remove a provided element from the array if possible*/
            if(*size_array != 0){
            Delete_Element(array, size_array, number);
            }
            
            else{
                printf("Sorry! The array is empty; no elements can be removed from it. Please add elements first to perform this action!.\n");
            }
            break;

        case 'A':
            /*add an element to the array at any desired position if possible*/
            if(*size_array < SIZE){
                Add_Where_Requested(array, size_array, number);
            }
            
            else{
                printf("Sorry! It's not possible to add another element to the array; it's full. Remove an element to add a new number!.\n");
            }
            break;
    }
}

void Add_Last_Position(int *array, int *size_array, int number){
    /*simply, I add the number to the last position of the array*/
    array[*size_array] = number;
    (*size_array)++;
}

void Delete_Element(int *array, int *size_array, int number_to_delete){
    int i, j, aux;

    for(i = 0; i < *size_array; i++){
        if(array[i] == number_to_delete){
            array[i] = 0;
        }
    }

    for(i = 0; i < *size_array - 1; i++){
        for(j = i + 1; j < *size_array; j++){
            
            if(array[i] == 0){
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }

    (*size_array)--;
}

void Add_Where_Requested(int *array, int *size_array, int number){
    int i, j;

    printf("In which position do you want to place the number?: ");
    int position = Get_Number();

    while(position > *size_array){
        printf("Invalid position! Please enter a position between 0 and %d!: ", *size_array);
        position = Get_Number();
    }

    for(i = *size_array; i >= position - 1; i--){
        array[i + 1] = array[i];
    }

    array[position - 1] = number;
    (*size_array)++;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int arr[SIZE] = {1, 2, 4, 3, 6, 5}, initial_size = 6, size = initial_size;

    /*I am testing the functions*/

    Order_the_Array(arr, size);
    for(int i = 0; i < size - 1; i++){
        assert(arr[i] <= arr[i + 1]);
    }

    Add_Last_Position(arr, &size, 10);
    assert(size == initial_size + 1 && arr[size - 1] == 10);

    Delete_Element(arr, &size, 10);
    assert(size == initial_size);

    /*The decision not to test the other functions stems from the anticipated substantial code modifications required 
    to facilitate automation.*/

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}