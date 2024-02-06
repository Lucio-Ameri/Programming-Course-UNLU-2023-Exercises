#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
int Get_Number();
char Get_Char();
void Show_Array(char array[], int size);
void Load_Array(char *array, int size);
int Sorted(char array[], int size);
void Testing();

int main(){
    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    printf("Enter the size of the array: ");
    int size = Get_Number(), flag;
    char array[size];

    /*I load the array and display it on the screen*/
    Load_Array(array, size);
    Show_Array(array, size);

    system("Pause");
    system("cls");

    /*I call the function 'Sorted' to see if the user-provided array is sorted*/
    flag = Sorted(array, size);

    /*I use a 'switch' statement to print a text according to the result of the previous function*/
    switch(flag){
        
        case 0:
            printf("The provided array is ordered!\n");
            break;

        case 1:
            printf("The provided array is unordered!\n");
            break;
    }

    system("Pause");
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

    return word;
}

void Show_Array(char array[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4c", array[i]);
    }
    printf("\n\n");
}

void Load_Array(char *array, int size){
    /*I declare the variables*/
    int i;
    char words;

    /*With each interaction, I ask the user for a new letter*/
    printf("You should enter %d letters (one at a time)!\n", size);
    for(i = 0; i < size; i++){
        printf("Please enter letter number %d : ", i + 1);
        words = Get_Char();
        tolower(words);
        array[i] = words;
    }
    system("Pause");
    system("cls");
}

int Sorted(char array[], int size){
    /*I declare the variables*/
    int i, flag = 0;

    /*If the array is not sorted from least to greatest, the cycle terminates and returns the result of the flag*/
    for(i = 0; i < size - 1; i++){
        if(array[i] > array[i+1]){
            flag = 1;
            return flag;
        }
    }

    return flag;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);
    
    /*I declare the variables*/
    char array[] = {'a', 'b', 'c', 'd', 'e'}, array2[] = {'a', 'c', 'b', 'e', 'd'};

    /*I am testing the function*/
    assert(Sorted(array, 5) == 0);
    assert(Sorted(array2, 5) == 1);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}