#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Functions Prototypes*/
void Load_Array(int *array, int number);
void Show_Array(int *array, int number);
void Move_Positions(int *array, int number);
int Get_Number();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    printf("Enter the size of the array: ");
    int size = Get_Number();

    int array[size];

    /*calls the 'load array' and 'show array' functions*/
    Load_Array(array, size);
    printf("The array is: ");
    Show_Array(array, size);

    system("Pause");

    /*calls the 'move positions' to move a position to the right and 'show array' functions*/
    Move_Positions(array, size);
    printf("with the modification, the array looks like this: ");
    Show_Array(array, size);

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

void Load_Array(int *array, int number){
    /*I declare the variables*/
    int i;

    /*loads the array*/
    for(i = 0; i < number; i++){
        array[i] = rand() % 100 + 1;
    }

}

void Show_Array(int *array, int number){
    /*I declare the variables*/
    int i;
    
    /*Shows the array*/
    for(i = 0; i < number; i++){
        printf("%3d", array[i]);
    }
    printf("\n");
}

void Move_Positions(int *array, int number){
    /*I declare the variables*/
    int i, aux = array[number - 1];

    /*I traverse the vector from right to left, moving the positions of the numbers from left to right*/
    for(i = number - 1; i > 0; i--){
        array[i] = array[i - 1]; 
    } 

    array[0] = aux;
}