#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 50

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Quantity_of_Positives(int *array, int number);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[size], positives;

    /*I load the array and display it on the screen*/
    printf("The array is: ");
    Load_Array(array);
    Show_Array(array);

    /*I call the 'Quantity of Positives' function to find out the number of Positives in the array*/
    positives = Quantity_of_Positives(array, size);
    
    /*I display on the screen the quantity of Positives in the array*/
    printf("The array has %d positive numbers.\n", positives);

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

int Quantity_of_Positives(int *array, int number){
    /*I declare the variables*/
    int i, positives = 0;

    /*each time array[i] is a Positive Number, the 'positives' counter increments by 1*/
    for(i = 0; i < number; i++){
        if(array[i] > 0){
            positives += 1;
        }
    }

    return positives;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int vector[] ={-1, 2, 1}, vector2[] ={0, 0, 0}, vector3[] ={0, 3, -3};

    /*I am testing the function*/
    assert(Quantity_of_Positives(vector, 3) == 2);
    assert(Quantity_of_Positives(vector2, 3) == 0);
    assert(Quantity_of_Positives(vector3, 3) == 1);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}