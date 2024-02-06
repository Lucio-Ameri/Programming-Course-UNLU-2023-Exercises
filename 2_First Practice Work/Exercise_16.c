#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 50

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Get_Number();
int Match_Count(int *array, int *array2, int number);
int First_Match(int array[]);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));
    
    /*I declare the variables*/
    int array1[size], array2[size], matches, first_appearance, number;

    /*I load the array and display it on the screen*/
    printf("The array is: ");
    Load_Array(array1);
    Show_Array(array1);

    /*I enter a valid number from the keyboard and store it in this variable*/
    number = Get_Number();

    /*I call the functions and print the results obtained and requested in the exercise statement*/
    matches = Match_Count(array1, array2, number);
    first_appearance = First_Match(array2);

    printf("There were %d matches in the array\n", matches);
    printf("The first match occurred at position: %d\n", first_appearance);
    printf("The matches occurred at positions: ");
    Show_Array(array2);

    return 0;
}

void Show_Array(int array[]){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%-4d", array[i]);
    }
    printf("\n\n");
}

void Load_Array(int *array){
    /*I declare the variables*/
    int i;

    /*I use random numbers between 1 and 20 to fill the array*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 20) + 1;
    }
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

    return Number;
}

int Match_Count(int *array, int *array2, int number){
    /*I declare the variables*/
    int i, matches = 0;

    /*each time the condition is met, the 'matches' accumulator increments by 1*/
    for(i = 0; i < size; i++){
        if(number == array[i]){
            array2[matches] = i + 1;
            matches += 1;
        }
    }

    /*if there are no matches, it returns -1*/
    if(matches == 0){
        matches = -1;
    }
    
    return matches;
}

int First_Match(int array[]){
    /*I declare the variables*/
    int flag = array[0];
    
    return flag;
}