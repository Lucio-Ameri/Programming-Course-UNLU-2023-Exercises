#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define SIZE_ARRAY 1000

int Get_Number();
void Get_Option(char *option);
void Show_Array(int array[], int size);
void Load_Array(int *array, int size);
void Sort_Array(int *array, char order, int size);
void Testing();


int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    int size, array[SIZE_ARRAY];
    char option;

    /*I ask the user to enter the size of the array*/
    printf("Enter the size of the array: ");
    size = Get_Number(); 
    while (getchar() != '\n');

    /* I load and display the array on the screen*/
    Load_Array(array, size);
    Show_Array(array, size);

    /* I ask the user to indicate how they want to sort the array*/
    printf("How do you want to sort the array? (Enter 'A' for ascending order; 'D' for descending order): ");
    Get_Option(&option);

    /*I sort the array and show how it turned out*/
    Sort_Array(array, option, size);
    printf("The sorted array in the chosen way is: \n");
    Show_Array(array, size);

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

void Get_Option(char *option){
    /*I declare the variables*/
    int aux = 1;

    /*I generate a loop in which if the user enters anything other than the letters 'A' and 'D', it 
    prompts again until one of the mentioned letters is entered*/
    while(aux == 1){
        aux = 0;

        *option = getchar();
        *option = toupper(*option);
        system("cls");

        if(!isalpha(*option) || (*option != 'A' && *option != 'D')){
            printf("¡ Invalid input! Please enter one of the following letters ('A' to sort in ascending order or 'D' to sort in descending order): ");
            aux = 1;
        }
    }
}

void Show_Array(int array[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] in each iteration*/
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }

    printf("\n");
    system("Pause");
}

void Load_Array(int *array, int size){
    /*I declare the variables*/
    int i;

    /*I load the array with random numbers between 1 and 100*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 100) + 1;
    }
}


void Sort_Array(int *array, char order, int size){
    /*I declare the variables*/
    int i, j, temp;

    /*Depending on the option entered, I sort the array from 'least to greatest' or from 'greatest to least'*/
    switch (order) {
        case 'A':
        /*Sorting the array from 'least to greatest', in each iteration it compares the content of array[i] with that of array[j], 
        if array[i] is greater, it swaps positions with array[j]*/
            for (i = 0; i < size-1; i++) {
                
                for (j = 0; j < size-i-1; j++) {
                
                    if (array[j] > array[j+1]) {
                        temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
                }
            }
            
            break;
        
        case 'D':
        /* Sorting the array from 'greatest to least', in each iteration it compares the content of array[i] with that of array[j], 
        if array[i] is smaller, it swaps positions with array[j]*/
            for (i = 0; i < size-1; i++) {
                
                for (j = 0; j < size-i-1; j++) {
                    
                    if (array[j] < array[j+1]) {
                        temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
                }
            }

            break;
    }
}


void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int i, j;
    int test_Array[4] = {2, 1, 4, 3};
    int result_array[4] = {1, 2, 3, 4};
    int test_Array2[4] = {2, 1, 4, 3};
    int result_array2[4] = {4, 3, 2, 1};
    char option1 = 'A';
    char option2 = 'D';

    /*I am testing the functions*/
    Sort_Array(test_Array, option1, 4);
    Sort_Array(test_Array2, option2, 4);

    for(i = 0; i < 4; i++){
        assert(test_Array[i] == result_array[i]);
    }

    for(j = 0; j < 4; j++){
        assert(test_Array2[j] == result_array2[j]);
    }

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}