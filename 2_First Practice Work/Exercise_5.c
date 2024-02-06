#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 30

/*Functions Prototypes*/
void Show_Array(char *array, int number);
void Load_Array(char *array, int number);
int Get_Random_Number();
void Insert_Letters(char *array, int number_A, int number_B);


int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    char array[size]; 
    int number_A, number_B;

    /*I load and display the array loaded with 'X'*/
    printf("the array is this: ");
    Load_Array(array, size);
    Show_Array(array, size);

    /*I load random numbers into variables 'number A' and 'number B'*/
    number_A = Get_Random_Number();
    number_B = Get_Random_Number();

    /*f they are equal, I ask for 'number B' again until they are different*/
    while(number_A == number_B){
        number_B = Get_Random_Number();
    }

    /*I display 'A' and 'B*/
    printf("'A' position: %d\n", number_A);
    printf("'B' position: %d\n", number_B);
    
    /*I call 'insert_letters' and display the modified array*/
    Insert_Letters(array, number_A, number_B);
    printf("having inserted the letters A and B, the array looks like this: ");
    Show_Array(array, size);

    return 0;
}

int Get_Random_Number(){
    /*I generate a number between 0 and 30*/
    return rand() % size;
}

void Load_Array(char *array, int number){
    /*I declare the variables*/
    int i;

    /*loads the array*/
    for(i = 0; i < number; i++){
        array[i] = 'X';
    }

}

void Show_Array(char *array, int number){
    /*I declare the variables*/
    int i;
    
    /*Shows the array*/
    for(i = 0; i < number; i++){
        printf("%c  ", array[i]);
    }
    printf("\n");
}

void Insert_Letters(char *array, int number_A, int number_B){
    /*I insert 'A' and 'B' at the respective position*/
    array[number_A - 1] = 'A';
    array[number_B - 1] = 'B';
}