#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 100

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Find_Max(int *array, int N);
void Testing_Functions();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing_Functions();

    /*I declare the variables*/
    int array[size], max_number;

    /*I load the array and display it on the screen*/
    printf("The array is: ");
    Load_Array(array);
    Show_Array(array);

    /*I receive the result from the 'Find Max' function and display on the screen the maximum number that was found*/
    max_number = Find_Max(array, size);
    printf("'%d' is the largest number that the array has.\n", max_number);

    system("Pause");
    system("cls");

    return 0;
}

void Show_Array(int array[]){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }
    printf("\n\n");
}

void Load_Array(int *array){
    /*I declare the variables*/
    int i;

    /*I use random numbers between -10 and 10 to fill the array*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 20) - 10;
    }
}

int Find_Max(int *array, int N){
    /*I declare the variables*/
    int i, number = -10000;

    /*With each iteration, the content of array[i] is compared to the content of 'number'; if it is greater than 
    'number', 'number' becomes the content of array[i]*/
    for(i = 0; i < N; i++){
        if(array[i] > number){
            number = array[i];
        }
    }

    return number;
}

void Testing_Functions(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    int array1[] = {3, 1, -1, 0, -15}; 
    int array2[] = {-3, -1, -7, -13, -15};

    /*Testing Find_Max*/
    assert(Find_Max(array1, 5) == 3);
    assert(Find_Max(array2, 5) == -1);

    printf("The programs are running normally!\n");
    system("Pause");
    system("cls");
}