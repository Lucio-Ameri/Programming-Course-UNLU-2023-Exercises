#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 30

/*Functions Prototypes*/
void Show_Array(char *array);
void Load_Array(char *array);
int Get_Random_Number();
void Insert_Letters(char *array, int number_A, int number_B);
int Distance(char *array);
void Testing();


int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    char array[size]; 
    int number_A, number_B, distance;

    /*I load and display the array loaded with 'X'*/
    printf("the array is this: ");
    Load_Array(array);
    Show_Array(array);

    system("Pause");
    system("cls");

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
    Show_Array(array);

    system("Pause");

    /*I calculate the distance between the two letters and then show it on the screen*/
    distance = Distance(array);
    printf("The distance between the two letters is %d positions\n", distance);

    system("Pause");
    system("cls");

    return 0;
}

int Get_Random_Number(){
    /*I generate a number between 0 and 30*/
    return rand() % size;
}

void Load_Array(char *array){
    /*I declare the variables*/
    int i;

    /*loads the array*/
    for(i = 0; i < size; i++){
        array[i] = 'X';
    }

}

void Show_Array(char *array){
    /*I declare the variables*/
    int i;
    
    /*Shows the array*/
    for(i = 0; i < size; i++){
        printf("%c  ", array[i]);
    }
    printf("\n");
}

void Insert_Letters(char *array, int number_A, int number_B){
    /*I insert 'A' and 'B' at the respective position*/
    array[number_A - 1] = 'A';
    array[number_B - 1] = 'B';
}

int Distance(char *array){
    /*I declare the variables*/
    int i = 0, Find = 0, counter = -1;

    /*The loop runs until the 2 letters are found*/
    while(Find != 2){
        /*You start counting iterations as if it were distance if the condition is met*/
        if(Find > 0){
            counter += 1;
        }

        /*increments the variable if any of the letters are found*/
        if(array[i] == 'A' || array[i] == 'B'){
            Find += 1;
        }

        i++;
    }

    return counter;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int result = 1;
    char vector[size];

    /*I am testing the function*/
    Load_Array(vector);
    Insert_Letters(vector, 1, 3);

    assert(Distance(vector) == result);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}